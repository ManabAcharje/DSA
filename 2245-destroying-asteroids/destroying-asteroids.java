class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long m = mass;
        for (int x : asteroids) {
            if (m >= x)
                m += x;
            else {
                return false;
            }
        }
        return true;
    }
}