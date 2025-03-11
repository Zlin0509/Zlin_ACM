#include <bits/stdc++.h>
using namespace std;

// IMPORTANT: This is an interactive solution.
// It communicates with the judge using queries of the form:
//   ? i j k
// and reading the judge’s reply (an integer).
// When an empty triangle is found, it outputs:
//   ! i j k
// and then flushes the output.

// In our solution we use a “triangle-shrinking” procedure.
// Start with triangle (a,b,c) = (1,2,3).
// Then, while a query on (a,b,c) returns a nonzero answer p (i.e. a point p inside),
// we try to “shrink” the triangle by replacing one of the vertices with p.
// In particular, we try the three subtriangles (p, b, c), (a, p, c) and (a, b, p).
// If any one of these is empty (query returns 0), then we have found a valid answer;
// otherwise we update the triangle (for example, we may update a = p) and continue.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        // If there are exactly three points, the only triangle is empty.
        if(n == 3){
            cout << "! 1 2 3" << "\n";
            fflush(stdout);
            continue;
        }

        // Start with an arbitrary triangle
        int a = 1, b = 2, c = 3;

        // Loop until we have an empty triangle.
        while (true) {
            cout << "? " << a << " " << b << " " << c << "\n";
            fflush(stdout);
            int inside;
            cin >> inside;
            if (inside == 0) {
                // Our current triangle is empty.
                cout << "! " << a << " " << b << " " << c << "\n";
                fflush(stdout);
                break;
            }
            // Otherwise, we got an index p of some point inside (a,b,c).
            int p = inside;

            // Try replacing vertex a:
            cout << "? " << p << " " << b << " " << c << "\n";
            fflush(stdout);
            int res;
            cin >> res;
            if(res == 0) {
                // The triangle (p,b,c) is empty. We can output that.
                a = p;  // update a to p (or directly answer)
                cout << "! " << a << " " << b << " " << c << "\n";
                fflush(stdout);
                break;
            }
            // Try replacing vertex b:
            cout << "? " << a << " " << p << " " << c << "\n";
            fflush(stdout);
            cin >> res;
            if(res == 0) {
                b = p;
                cout << "! " << a << " " << b << " " << c << "\n";
                fflush(stdout);
                break;
            }
            // Try replacing vertex c:
            cout << "? " << a << " " << b << " " << p << "\n";
            fflush(stdout);
            cin >> res;
            if(res == 0) {
                c = p;
                cout << "! " << a << " " << b << " " << c << "\n";
                fflush(stdout);
                break;
            }
            // None of the subtriangles are empty.
            // Replace one vertex arbitrarily (say, a) by p so that the triangle shrinks.
            a = p;
            // and continue the process
        }
    }
    return 0;
}
