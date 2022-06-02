
public class Solution {

    public long maximumImportance(int numberOfCities, int[][] roads) {
        int[] connections = new int[numberOfCities];
        for (int[] road : roads) {
            ++connections[road[0]];
            ++connections[road[1]];
        }
        Arrays.sort(connections);
        AtomicInteger cityValue = new AtomicInteger(0);
        return Arrays.stream(connections).asLongStream()
                .map(cityConnections -> cityConnections * (cityValue.incrementAndGet()))
                .sum();
    }
}
