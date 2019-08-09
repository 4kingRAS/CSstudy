package com.kkkk.patA;

import java.util.*;

/**
 * @author Yulin.Wang
 * @date 2019-07-28
 * @description
 **/
//TODO:

public class PublicBikeADV1018 {

    final int INF = 99999;

    int c;
    int n;
    int sp;
    int edge;

    int[][] m;
    int[] cap;
    boolean[] visit;

    Stack<Integer>[] pre;
    Stack<Integer> path, temp;
    int minNeed = INF;
    int minRemain = INF;

    public int dijkstra(int s) {
        int[] d = new int[n+1];
        Arrays.fill(d, INF);
        d[s] = 0;

        for (int i = 0; i <= n; i++) {
            int min = INF;
            int u = -1;  // if s cant connect others
            for (int j = 0; j <= n; j++) {
                if (!visit[j] && d[j] < min) {
                    u = j;
                    min = d[j];
                }
            }

            if (u == -1) { return 0; } //none of nodes could connect origin

            visit[u] = true;  // node u ,visited.  d[u] is minimal.
            for (int v = 0; v <= n; v++) {
                if (!visit[v] && m[u][v] != INF) {// just search unvisited node
                    int cur = d[u] + m[u][v];
                    if (cur < d[v]) {
                        d[v] = cur;
                        pre[v].clear();
                        pre[v].push(u);
                    } else if (cur == d[v]) {
                        pre[v].push(u); // generate best path.
                    }
                }
            }

        }
        return 1;
    }

    public void dfs(int station) {
        if (station == 0) {
            int need = 0, remain = 0;
            temp.push(station);

            for (int i = temp.size() - 1; i >= 0; i--) {
                int s = temp.get(i);
                if (cap[s] >= 0) {
                    remain += cap[s];
                } else {
                    if (remain + cap[s] > 0) {  // remain > abs(cap)
                        remain += cap[s];
                    } else {
                        need += 0 - cap[s] - remain;
                        remain = 0;
                    }
                }
            }
            if (need < minNeed) { // 1.shortest : depth first 2.min need
                minNeed = need;
                path = (Stack<Integer>) temp.clone();
                minRemain = remain;
            } else if (need == minNeed && remain < minRemain) { //3.min take from PBMC
                minRemain = remain;
                path = (Stack<Integer>) temp.clone();
            }
            temp.pop();
            return;
        }
        temp.push(station);
        for (int i = 0; i < pre[station].size(); i++) {
            dfs(pre[station].get(i)); //depth first, search every prefix
        }
        temp.pop();
    }

    public void init() {

        Scanner sc = new Scanner(System.in);
        c = sc.nextInt();
        n = sc.nextInt(); // 0 is PBMC, NODE start from 1 to n
        sp = sc.nextInt();
        edge = sc.nextInt();

        m = new int[n+1][n+1];
        cap = new int[n+1];
        visit = new boolean[n+1];
        Arrays.fill(visit, false);
        pre = new Stack[n+1];
        for (int i = 0; i < n+1; i++) {
            pre[i] = new Stack<>();
        }
        temp = new Stack<>();
        path = new Stack<>();

        for (int i = 1; i < n+1; i++) {
            cap[i] = sc.nextInt() - c/2; // simplify: capacity > half is positive
        }

        for (int i = 0; i <= n; i++) {
            Arrays.fill(m[i], INF);
        }

        for (int i = 0; i < edge; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            m[s][e] = sc.nextInt();
            m[e][s] = m[s][e];
        }
    }

    public void print() {
        System.out.print(minNeed + " ");
        for (int i = path.size() - 1; i >= 0; i--) {
            System.out.print(path.get(i).toString());
            if (i > 0) System.out.print("->");
        }
        System.out.print(" " + minRemain);
    }


    public static void main(String[] args) {

        PublicBikeADV1018 p = new PublicBikeADV1018();
        p.init();
        p.dijkstra(0);
        p.dfs(p.sp);
        p.print();

    }

}
