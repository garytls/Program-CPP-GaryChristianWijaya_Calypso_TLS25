#include <iostream>
using namespace std;

string getColor(int elapsed) {
    int cycle = elapsed % 103; // total siklus = 103 detik

    if (cycle < 3) return "Kuning";         // 0–2
    else if (cycle < 83) return "Merah";    // 3–82
    else return "Hijau";                    // 83–102
}

int main() {
    int start = 45; // titik awal, detik 45 = kuning
    int times[] = {80, 135, 150, 212};
    int n = 4;

    for (int i = 0; i < n; i++) {
        int elapsed = times[i] - start;
        cout << "Detik " << times[i] << " -> "
             << getColor(elapsed) << endl;
    }

    return 0;
}
