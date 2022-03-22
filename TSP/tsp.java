import java.util.Scanner;

class tsp {
    final int INT_MAX = 99999999;
    static int n = 4;
    //mang sau de luu khoang cach giua cac dinh
    static int[][] dist = new int[1000][1000];
    //mang sau de luu cac khoang cach da duoc tinh truoc (quy hoach dong):
    static int[][] tempDist = new int[1000][1000];
    //string luu tien trinh di:
    static int[][] path = new int[1000][1000];
    static int VISITED_ALL = (1 << n) - 1;
    static int start;

    public static int TSP(int mask, int pos) {
        //neu da tham het cac dinh thi return:
        if (mask == VISITED_ALL) {
            return dist[pos][0];
        }
    
        //neu khoang cach da duoc tinh truoc thi tai su dung:
        if (tempDist[mask][pos] != -1) {
            return tempDist[mask][pos];
        }
    
        int minWeight = 999999;
        int minPos = 999999;
        //dung for de tim den nhung dinh chua duoc tham
        for (int i = 0; i < n; i++) {
            //neu chua dinh chua duoc tham thi:
            if ((mask & (1 << i)) == 0) {
                int newWeight = dist[pos][i] + TSP(mask | (1 << i), i);
                if (minWeight > newWeight) {
                    minWeight = newWeight;
                    minPos = i;
                }
            }
        }
        //luu vi tri cac dinh de quang duong ngan nhat
        path[mask][pos] = minPos;
    
        return tempDist[mask][pos] = minWeight;
    }
    //ham chay sau khi da tinh duoc TSP
    public static void showPath_TSP(int mask, int pos) {
        if (pos == start) {
            System.out.print(start + " ");
        }
        if (path[mask][pos] != -1) {
            int minPos = path[mask][pos];
            System.out.print(minPos + " ");
            showPath_TSP(mask | (1 << minPos), minPos);
        } else {
            System.out.println(start + " ");
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        start = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = scanner.nextInt();
            }
        }

        VISITED_ALL = (1 << n) - 1;
        //khoi tao 1 mang ban luu khoang cach da duoc tinh, gia tri ban dau la -1
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                tempDist[i][j] = -1;
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                path[i][j] = -1;
            }
        }
    
        System.out.println(TSP(1, start));
        showPath_TSP(1, start);
        scanner.close();
    }
}
