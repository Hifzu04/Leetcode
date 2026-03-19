func numberOfSubmatrices(grid [][]byte) int {
	n := len(grid)
	m := len(grid[0])
	// Initialize 2D slices for cumulative sums
	cumSumX := make([][]int, n)
	cumSumY := make([][]int, n)
	for i := range cumSumX {
		cumSumX[i] = make([]int, m)
		cumSumY[i] = make([]int, m)
	}
	cnt := 0

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			// Check current cell values

			if grid[i][j] == 'X' {
				cumSumX[i][j] = 1
			} else {
				cumSumX[i][j] = 0
			}
			if grid[i][j] == 'Y' {
				cumSumY[i][j] = 1
			} else {
				cumSumY[i][j] = 0
			}

			// Add top neighbor
			if i > 0 {
				cumSumX[i][j] += cumSumX[i-1][j]
				cumSumY[i][j] += cumSumY[i-1][j]
			}
			// Add left neighbor
			if j > 0 {
				cumSumX[i][j] += cumSumX[i][j-1]
				cumSumY[i][j] += cumSumY[i][j-1]
			}
			// Subtract top-left diagonal neighbor (Inclusion-Exclusion)
			if i > 0 && j > 0 {
				cumSumX[i][j] -= cumSumX[i-1][j-1]
				cumSumY[i][j] -= cumSumY[i-1][j-1]
			}

			// Condition: Equal counts of X and Y, and at least one X
			if cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0 {
				cnt++
			}
		}
	}

	return cnt
}