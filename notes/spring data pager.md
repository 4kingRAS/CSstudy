
# 记spring data page分页器的一个小坑

问题倒也不难，但是比较绕，记录一下。

做的项目有用到 Spring data的分页器，本来应该在JpaReposity里就直接生成page的。但是情况特殊，有时候要转换现成的list来分页，于是我的需求是这样的：

```java
List<User> ulist = userService.findAllUser();
Pageable pageable = PageRequest.of(0, 5, Sort.Direction.ASC,"id");
Page<User> datas = new PageImpl<>(clist, pageable, clist.size());
```
要传一个9个元素的list给page，page为第一页，每页5条。
看一下doc：
```java
public static PageRequest of(int page,int size,Sort.Direction direction,String... properties)

Creates a new PageRequest with sort direction and properties applied.
Parameters:
page - zero-based page index.
size - the size of the page to be returned.
```
很好，没毛病，page 0， size 5。
>public PageImpl(List<T> content, Pageable pageable, long total)

page的实现类，Constructor of PageImpl.乍看也没什么毛病，直接编译运行，页确实给我分了两页，index也是第0页，然而第0页却显示了9条！很烦，前端分页器的totalPages 和getNumber()都是对的，就是不明白为什么给分了整个list。

首先，看源码：
pageable的实现没什么问题，从运行结果看也不是什么问题,然后看pageimpl的：
```java
	public PageImpl(List<T> content, Pageable pageable, long total) {

		super(content, pageable);

		this.total = pageable.toOptional().filter(it -> !content.isEmpty())//
				.filter(it -> it.getOffset() + it.getPageSize() > total)//
				.map(it -> it.getOffset() + content.size())//
				.orElse(total);
	}
```
看了下注释，total是总数啊，虽然不明白这些断言是什么。。

https://stackoverflow.com/questions/26720768/spring-data-pageimpl-not-returning-page-with-the-correct-size

https://stackoverflow.com/questions/39930897/springdata-pageimpl-totalelements-is-wrong

上网一搜，不少人跟我一样，不过他们要么建议用pagelistholder，要么也没说清楚怎么回事。直到我看到这个：
https://stackoverflow.com/questions/45740722/spring-data-page-gettotalelements-is-incorrect-on-the-last-page

于是我找到spring data commons的[github项目](https://github.com/spring-projects/spring-data-commons/blob/master/src/main/java/org/springframework/data/domain/PageImpl.java)
```java
/**
	* Constructor of {@code PageImpl}.
	@param content the content of this page, must not be {@literal null}.
	@param pageable the paging information, must not be {@literal null}.
	@param total the total amount of items available. The total might be adapted considering the length of the content given, if it is going to be the content of the last page. This is in place to mitigate inconsistencies.
*/
```
考验英文阅读的细节了，再结合pageimpl的源码终于明白了，只是一场误会。

springdata早期版本只是`this.total = total`, 后面为了解决最后一页显示条数的特殊性加了一些断言，`.map(it -> it.getOffset() + content.size())`先判断为不为空，然后判断offset，也就是当前page* page.size 大不大于total。大于说明是最后一页，然后会显示所传content的所有内容。

**也就是说total确实是list.size()，但是content要传的是你这一页要显示的sublist！**

一不小心就糊涂了，还是得仔细看说明文档。但是这种设计也是够sb的，参数说明应该清楚一点啊

