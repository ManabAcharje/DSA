class Solution {

    public int findCheapestPrice(int n, int[][] flights,
                                 int src, int dst, int k) {

        Map<Integer, List<int[]>> adjList = new HashMap<>();

        for (int[] f : flights) {
            int u = f[0];
            int v = f[1];
            int wt = f[2];

            adjList.computeIfAbsent(u, key -> new ArrayList<>())
                   .add(new int[]{v, wt});
        }

        PriorityQueue<int[]> pq =
                new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // {cost, node, stops}
        pq.offer(new int[]{0, src, 0});

        int[][] dist = new int[n][k + 2];

        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        dist[src][0] = 0;

        while (!pq.isEmpty()) {

            int[] curr = pq.poll();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            if (node == dst) {
                return cost;
            }

            if (stops == k + 1) {
                continue;
            }

            for (int[] neighbor :
                    adjList.getOrDefault(node, Collections.emptyList())) {

                int nextNode = neighbor[0];
                int price = neighbor[1];

                int newCost = cost + price;

                if (newCost < dist[nextNode][stops + 1]) {

                    dist[nextNode][stops + 1] = newCost;

                    pq.offer(new int[]{
                            newCost,
                            nextNode,
                            stops + 1
                    });
                }
            }
        }

        return -1;
    }
}