#include<stdio.h>
<<<<<<< HEAD
int main()
{
    int i, j, k;
    for (i = 1; i < 5; i++)
        for (j = 1; j < 5; j++)
            for (k = 1; k < 5; k++)
            {
                if (i != k && i != j && j != k)
                    printf("%d%d%d\t", i, j, k);
            }
    return 0;
=======
void main()
{
	int x, n, m;
	for (x = 1; x < 168; x++) {
		for(n = 1; n < 168; n++) {
			if ((x + 100) == (n * n)){
				for (m = 1; m < 168; m++) {
					if ((x+100+168)==(m*m)){
						printf("%d\n",x); continue;
					}
				}				
			}
		}
	}
>>>>>>> c51ae12 (提交文件)
}
