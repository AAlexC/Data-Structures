#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct pila{ long long int val, eli; };
stack <pila> edificio;
pila temp;
long long int n, i, a, c, maxT = -1, multiplica, izqEli;
int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> a;
        izqEli = 0;
        c = 0;
        while(!edificio.empty() && a < edificio.top().val){
            c++;
            multiplica = edificio.top().eli;
            c += multiplica;
            maxT = max(maxT,  c * edificio.top().val);
            edificio.pop();
        }
        maxT = max(maxT, a);
        maxT = max(maxT, c*a);
        izqEli += c;
        temp.val = a;
        temp.eli = izqEli;
        edificio.push(temp);
    }
    c = 0;
    while(!edificio.empty()){
        c++;
        multiplica = edificio.top().eli;
        c += multiplica;
        maxT = max(maxT, c * edificio.top().val);
        edificio.pop();
    }
    cout << maxT<<"\n";
    return 0;
}
