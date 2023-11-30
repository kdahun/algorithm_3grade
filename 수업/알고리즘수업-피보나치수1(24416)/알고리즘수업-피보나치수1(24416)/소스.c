# include<stdio.h>

int count1 = 1;
int count2 = 0;

int fib(n) {
	if (n == 1 || n == 2) {

		return 1;
	} 
	else {
		count1++;
		return (fib(n - 1) + fib(n - 2));
	}
}

int fibonacci(n) {
	int arr[44] = { 0, };
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 2; i < n; i++) {
		count2++;
		arr[i + 1] = arr[i - 1] + arr[i];
	}
	return arr[n + 2];
}

int main() {

	//입력 : 첫째줄에 n은(5<=n<=40)이다.
	//출력 : zhem
	int n = 0;
	int a = 0;
	scanf_s("%d", &n);
	a=fib(n);
	a=fibonacci(n);
	printf("%d %d", count1, count2);

	return 0;
}