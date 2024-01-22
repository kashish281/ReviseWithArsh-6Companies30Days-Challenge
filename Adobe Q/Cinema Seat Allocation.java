class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int numberOfFamilies = 0;
        Map<Integer, boolean[]> rows = new HashMap<>();
        for (int[] reservedSeat : reservedSeats) {
            rows.computeIfAbsent(reservedSeat[0], k -> new boolean[11])[reservedSeat[1]] = true;
        }
        numberOfFamilies += 2 * (n - rows.size());
        for (boolean[] usedSeats : rows.values()) {
            numberOfFamilies += findFreeRows(usedSeats);
        }
        return numberOfFamilies;
    }

    private int findFreeRows(boolean[] taken) {
        int families = 0;
        if (!taken[2] && !taken[3] && !taken[4] && !taken[5]) {
            families++;
        }
        if (!taken[6] && !taken[7] && !taken[8] && !taken[9]) {
            families++;
        }
        if (families == 0 && !taken[4] && !taken[5] && !taken[6] && !taken[7]) {
            families++;
        }
        return families;
    }
}