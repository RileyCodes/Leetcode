public class Solution {
    public int ProjectionArea(int[][] grid) {
        var topCount = grid.Sum(x => x.Count(y => y > 0));
        var Side1Count = grid.Sum(row => row.Max());
        var Side2Count = 0;
        for(var i = 0; i < grid[0].Length; ++i)
        {
            Side2Count += grid.Select(x => x[i]).Max();
        }
        
        return topCount + Side1Count + Side2Count;
    }
}

