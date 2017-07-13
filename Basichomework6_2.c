#include <stdio.h> 

int main(){
	int n, rowiter, row, col, minr, maxc, colmin, found = 1, count = 0;
	scanf("%d", &n);
	int nums[n][n], rowmax[n], maxindc[n];
	
	for(row = 0; row < n; row++){
		for(col = 0; col < n; col++){
			scanf("%d", &nums[row][col]);
			if(col == 0) {
				rowmax[row] = nums[row][col];
				maxindc[row] = col;
			}
			else if(rowmax[row] < nums[row][col]) {
				rowmax[row] = nums[row][col];
				maxindc[row] = col;
			}
		}
	}
	
//	for(row = 0; row < n; row++){
//		printf("%d_%d_%d ", row, rowmax[row], maxindc[row]);
//	}
	
	for(row = 0; row < n; row++){
		colmin = rowmax[row];
		for(rowiter = 0; rowiter < n; rowiter++){
			if(rowiter == row ) continue;
			if(nums[rowiter][maxindc[row]] < colmin) found = 0;
		}
		if(found) {
			minr = row;
			maxc = maxindc[row];
			count++;
		}
		found = 1;
	}
	
	if(count) printf("%d %d\n", minr, maxc);
	else printf("NO\n");
	
	return 0;
}
