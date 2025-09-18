#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // panjang array

    int arr[1000];  // asumsi n <= 1000
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int val = arr[i];

        // jika indeks genap, lakukan pembalikan digit
        if (i % 2 == 0) {
            if (val == 0) {
                val = 0; // khusus untuk nol
            } else {
                int sign = 1;
                if (val < 0) { // simpan tanda negatif
                    sign = -1;
                    val = -val;
                }
                int rev = 0;
                while (val > 0) {
                    rev = rev * 10 + (val % 10);
                    val /= 10;
                }
                val = rev * sign;
            }
        }

        sum += val;
    }

    cout << sum << endl;
    return 0;
}
