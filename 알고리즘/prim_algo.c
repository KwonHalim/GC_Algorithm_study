//#include <stdio.h>
//#include <stdbool.h>
//#include <limits.h>
//
//#define V 3 // �׷����� ���� ��
//
//// �ּ� Ű ���� ã�� ���� ��ƿ��Ƽ �Լ�
//int findMinKey(int key[], bool mstSet[]) {
//    int minKey = INT_MAX, minIndex;
//    for (int v = 0; v < V; v++) {
//        if (!mstSet[v] && key[v] < minKey) {//���� �湮���� ���� ����̰�, v��° ��� ������ ���̰� ���� ���� �ͺ��� �۾ƾ���
//            minKey = key[v];
//            minIndex = v;
//        }
//    }
//    return minIndex;
//}
//
//// �ּ� ���� Ʈ���� ����ϴ� ��ƿ��Ƽ �Լ�
//void printMST(int parent[], int graph[V][V]) {
//    printf("Edge \tWeight\n");
//    for (int i = 1; i < V; i++) {
//        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
//    }
//}
//
//// ���� �˰���
//void primMST(int graph[V][V]) {
//    int parent[V];  // �ּ� ���� Ʈ������ �ش� ������ �θ� ����
//    //�θ�:���� ���� ��ġ
//    int key[V];     // ���������� �ּ� ����ġ
//
//    bool mstSet[V]; // �ּ� ���� Ʈ���� ���Ե� ���� ǥ��
//
//    for (int i = 0; i < V; i++) {
//        key[i] = INT_MAX;
//        mstSet[i] = false;
//    }
//
//    key[0] = 0;     // ���� ������ ����
//    parent[0] = -1; // ���� ������ �θ� ����
//
//    for (int count = 0; count < V - 1; count++) {
//        int u = findMinKey(key, mstSet);
//        mstSet[u] = true;
//
//        for (int v = 0; v < V; v++) {
//            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
//                parent[v] = u;
//                key[v] = graph[u][v];
//            }
//        }
//    }
//
//    printMST(parent, graph);
//}
//
//int main() {
//    int graph[V][V] = {
//        {0,2,10},
//        {2,0,4},
//        {10,4,0}
//    };
//
//    primMST(graph);
//
//    return 0;
//}



#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 7  // ����Ʈ���� ���� ����
#define INF 1000L // ��ΰ� ���� INFINITE�� ǥ���ϱ� ���� ���ǵ� ��� INF

int weight[MAX_VERTICES][MAX_VERTICES] = {// ����Ʈ���� �Ÿ��� ����� �迭�� ǥ��, INF�� �ٷΰ� �� �ִ� ��ΰ� ������ ���Ѵ�.
  {0,7,INF,INF,3,10,INF},
  {7,0,4,10,2,6,INF},
  {INF,4,0,2,INF,INF,INF},
  {INF,10,2, 0,INF,9,4},
  {3,2,INF,INF,0,INF,6},
  {10,6,INF,9,INF,0,INF},
  {INF,INF,INF,4,5,INF,0 }
};

int selected[MAX_VERTICES]; // ���õ� ������ ������ ���� �迭, ������ �ƴ��� �ȵƴ����� ǥ���Ѵ�.
int dist[MAX_VERTICES]; // �ּ��� �Ÿ� �������� ��� �迭, ���ο� �ּҰŸ��� ���� ������ ���ŵȴ�.

// �ּ� dist[v]���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
    int v, i; // ������ ������ ������ ���� v, �ݺ����� ���� ���� i

    for (i = 0; i < n; i++)
    {
        if (selected[i] == FALSE) {
            v = i;  // ���� ���õ��� ���� ������ ��ȣ�� v�� ����, �� �Լ� ���ະ 0���� n - 1���� ���ʴ�� ����ȴ�.
            break;
        }
    }

    // ������ ���õ� ������ ���� �ּҰŸ��� ���ϰ� �ִ� ���������� Ȯ���Ѵ�.
    for (i = 0; i < n; i++)
    {
        // ���õ��� ���� �������� ��ȸ�ϸ鼭 �ּҰŸ��� ���� ������ ã�Ƴ���.
        if (selected[i] = FALSE && (dist[i] < dist[v]))
            v = i;  // �� ���� �Ÿ��� �����Ѵٸ� �ش� ������ �����Ѵ�.
    }

    return(v);  // �ּ��� �Ÿ��� ���� ������ ���õ����Ƿ� ���� ��ȣ�� �����Ѵ�.
}

// Prim, s�� ���� ����
void prim(int s, int n)
{
    int i, u, v;

    for (u = 0; u < n; u++)  // dist�迭�� selected�迭�� ������ �ʱ�ȭ
    {
        dist[u] = INF;
        selected[u] = FALSE;
    }

    dist[s] = 0;  // ���������� ������������ �Ÿ��� 0�̴�. �ڱ��ڽ��� ��ȯ�ϴ� ��δ� ���ٰ� �����Ѵ�.

    for (i = 0; i < n; i++)
    {
        // ���ϵ� ���� ��ȣ�� u�� �����Ѵ�. u�� �ּҰŸ��� ������ ����. ������ ���� �� �����ϴ� ȿ���� �����´�.
        u = get_min_vertex(n);
        selected[u] = TRUE; // �ּҰŸ��� ���� ������ ����(u)�� �˾Ƴ����� �ش� ������ �����ߴٰ� ǥ���Ѵ�.

        // ���� ��ΰ� ���ٸ� �Լ��� �����Ѵ�. �������� ����Ʈ���� ������ ���Դٸ� ����� ���� ���� ���̴�.
        if (dist[u] == INF) return;

        printf("%d ", u); // �湮�� ����(u)�� ����Ѵ�.

        for (v = 0; v < n; v++)  // �� ������ �츮�� ���Ӱ� �߰��� ������ �����ϴ� �����̴�.
            // �������� ��ΰ� �߰ߵǾ� INF ���� ����Ÿ��� �ٲ�� ������
            // ������ ����Ÿ����� �� ª�� �Ÿ��� �߰ߵ� �� ������ �����ϴ� ������ ���ԵǾ� �ִ�.
        {
            // ���õ� u ������ �������� ����(u)�� ����Ǿ� �ִ� ���������� �Ÿ��� ���� ���Ѵ�.
            if (weight[u][v] != INF)  // ���� u�� ������ �Ǿ��ְ�
            {
                // ���� ���õ��� �ʾ����� �ش� ��(weight[u][v])�� ���̰� ������ dist[v] ������ �۴ٸ�
                if (selected[v] == FALSE && weight[u][v] < dist[v])
                    dist[v] = weight[u][v]; // dist[v]�� ���� �������ش�.
                for (int i = 0; i < MAX_VERTICES; i++) {
                    printf("%d ", dist[i]);
                }

                // ���Ӱ� �߰ߵǴ� �������� �ʹݿ� ����� �� �ִ� �� INF�� 1000���� ��������� �����̴�.
                // �츮�� ���� �׷����� ��ΰ����� ���� 100������ ���̱� ������ ���Ӱ� �߰ߵǴ� ������ �ִٸ�
                // �켱 ��ϵǰ� �� �� �� ª�� �Ÿ��� �����ϸ� ���ŵǴ� ���·� �� ���α׷��� �۵��Ѵ�.
            }
            printf("\n");
        }
    }
}

void main()
{
    prim(0, MAX_VERTICES);  // ���� ������ 7���� �׷������� 0�� ������ ����Ͽ� ���� �� �ִ� �ּҺ�����Ʈ���� ã�ƶ�.
}

/*************************************************
 ** End Line
*************************************************/