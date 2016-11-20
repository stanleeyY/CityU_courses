#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int arr[10000];
ofstream file;
int prime(int a[], int n) {
	clock_t start;
	double duration;
	start = clock();
	int cnt = 0;
	int i, p;
	bool isPrime;
	cnt += 3;
	for (i = 0, p = 2; p < n; p++) {
		cnt += 2;
		isPrime = true;
		cnt++;
		cnt += 2;
		for (int j = 2; j < p; j++) {
			cnt += 2;
			cnt += 2;
			if (p % j == 0) {
				isPrime = false;
				cnt++;
			}
		}
		cnt++;
		if (isPrime) {
			a[i] = p;
			cnt += 2;
			i++;
			cnt++;
		}
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	//printf("Case size: %d\t# of operations: %d\tTime cost: %lf\n", n, cnt, duration);
	file << n << "," << cnt << "," << duration << endl;
	return i;
}
int main() {
	//freopen("/Users/JerryLiu/Downloads/output.txt", "a", stdout);
	file.open("4b.csv");
	for (int i = 2; i <= 10000; i++) {
		prime(arr, i);
	}
	file.close();
	//fclose(stdout);
	return 0;
}
