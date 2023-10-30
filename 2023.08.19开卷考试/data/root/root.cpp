#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h> 
#include <random>

using namespace std;

int Max_n = 1000000009;

int jacobi(int p, int q) {
  if (p == 1) return 1;
  if (p % 2 == 0) {
    int r = jacobi(p / 2, q);
    if (q % 8 == 1 || q % 8 == 7) return r;
    else return -r;
  }
  if (p > q) return jacobi(p % q, q);
  else {
    int r = jacobi(q % p, p);
    if (p % 4 == 1 || q % 4 == 1) return r;
    else return -r;
  }
}

inline int getN(int p) {
  srand(20040313U);
  for (;;) {
    int x = rand() % (p - 1) + 1;
    if (jacobi(x, p) == -1) return x;
  }
  return -1;
}

inline int fastPow(int low, int high, int p) {
  int res = 1;
  while (high) {
    if (high & 1) res = (int) (1LL * res * low % p);
    high >>= 1;
    low = (int) (1LL * low * low % p);
  }
  return res;
}

int fun(int n, int p, int N, int h, int s) {
  if (h % 2 == 1)
    return (int) (1LL * fastPow(n, (h + 1) / 2, p) * fastPow(N, s / 2, p) % p);
  int x = (int) (1LL * fastPow(n, h / 2, p) * fastPow(N, s / 2, p) % p);
  if (x == 1) return fun(n, p, N, h / 2, s / 2);
  else return fun(n, p, N, h / 2, s / 2 + (p - 1) / 2);
}

int solve(int n, int p) {
  if (n == 0) return 0;
  if (jacobi(n, p) == -1) return -1;
  int N = getN(p);
  return fun(n, p, N, (p - 1) / 2, 0);
}

bool isPrime(int a) {
  if (a < 2) return 0;
  for (int i = 2; i * i <= a; ++i)
    if (a % i == 0) return 0;
  return 1;
}

int main() {
  int te, n, p;
  //scanf("%d", &te);
	
  srand(time(0));
  std::mt19937 rng(time(0));
  
  for (int i = 1; i <= 10;i++)
  {
  		string infile_name = std::to_string(i)+".in";
  		string outfile_name = std::to_string(i)+".out";
  		ofstream infile(infile_name);
  		ofstream outfile(outfile_name);
  		te = rng()%10000+1;

  		infile << te <<endl;
		for (int t = 1; t <= te; ++t) {
			//scanf("%d %d", &n, &p);
			n = rng()%Max_n;
			p = rng()%Max_n;
			while(!isPrime(p))
			{
				//cout<<p<<endl;
				p = rng()%Max_n;
			}
			infile<<n<<' '<<p<<endl;
			int x = solve(n, p);
			if (x == -1) outfile<<-1<<endl;
			else if (x == 0) outfile<<0<<endl;
			else {
			  int y = p - x;
			  if (x > y) outfile<<y<<' '<<x<<endl;
			  else outfile<<x<<' '<<y<<endl;
			}
		}
  }
  return 0;
}
