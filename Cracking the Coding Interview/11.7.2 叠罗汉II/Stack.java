package cracking_the_coding_interview;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Created by chenyang li.
 * <p/>
 * 叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。为了使叠成的罗汉更稳固，我们应该让上面的人比下面的人更轻一点。
 * 现在一个马戏团要表演这个节目，为了视觉效果，我们还要求下面的人的身高比上面的人高。请编写一个算法，计算最多能叠多少人，注意这里所有演员都同时出现。
 * 给定一个二维int的数组actors，每个元素有两个值，分别代表一个演员的身高和体重。同时给定演员总数n，请返回最多能叠的人数。保证总人数小于等于500。
 * <p/>
 * 测试样例：
 * [[1,2],[3,4],[5,6],[7,8]],4
 * 返回：4
 */
public class Stack {

    class Actor {
        int height;
        int weight;

        Actor(int height, int weight) {
            this.height = height;
            this.weight = weight;
        }
    }

    public int getHeight(int[][] actors, int n) {
        ArrayList<Actor> actors1 = new ArrayList<Actor>();
        ArrayList<Actor> actors2 = new ArrayList<Actor>();
        for (int i = 0; i < n; i++) {
            actors1.add(new Actor(actors[i][0], actors[i][1]));
            actors2.add(new Actor(actors[i][0], actors[i][1]));
        }

        // 先按照身高从高到低排序，再按照体重从大到小排序
        Collections.sort(actors1, new Comparator<Actor>() {
            public int compare(Actor o1, Actor o2) {
                if (o1.height > o2.height) {
                    return -1;
                } else if (o1.height < o2.height) {
                    return 1;
                } else if (o1.weight < o2.weight) {
                    return -1;
                } else if (o1.weight > o2.weight) {
                    return 1;
                }
                return 0;
            }
        });

        // 先按照体重从大到小排序，再按照身高从高到低排序
        Collections.sort(actors2, new Comparator<Actor>() {
            public int compare(Actor o1, Actor o2) {
                if (o1.weight > o2.weight) {
                    return -1;
                } else if (o1.weight < o2.weight) {
                    return 1;
                } else if (o1.height > o2.height) {
                    return -1;
                } else if (o1.height < o2.height) {
                    return 1;
                }
                return 0;
            }
        });

        int[] dp1 = new int[n];
        int[] dp2 = new int[n];

        int max1 = 0;
        for (int i = 0; i < n; i++) {
            dp1[i] = 1;
            max1 = 1;
            for (int j = 0; j < i; j++) {
                if (actors1.get(i).weight < actors1.get(j).weight && dp1[j] + 1 > max1) {
                    max1 = dp1[j] + 1;
                }
            }
            dp1[i] = max1;
        }

        int max2 = 0;
        for (int i = 0; i < n; i++) {
            dp2[i] = 1;
            max2 = 1;
            for (int j = 0; j < i; j++) {
                if (actors2.get(i).height < actors2.get(j).height && dp2[j] + 1 > max2) {
                    max2 = dp2[j] + 1;
                }
            }
            dp2[i] = max2;
        }

        max1 = max2 = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > max1) {
                max1 = dp1[i];
            }
            if (dp2[i] > max2) {
                max2 = dp2[i];
            }
        }

        return max1 > max2 ? max1 : max2;
    }

    public static void main(String[] args) {
        int[][] actors = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        Stack stack = new Stack();
        System.out.println(stack.getHeight(actors, 4));
    }
}
