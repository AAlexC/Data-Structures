#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1000002
long long RES[MAXN], n, h, r, i, j, temp1, temp2, enpila=-10000000000;
struct pila{ long long h, r , p; };
vector <pila> Pira;
pila aux, temp;
int main(){
cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for(i = 1; i <= n; i++){
      cin >> h >> r;
        RES[i] = r;
        while(!Pira.empty() && h > Pira.back().h){         
         j = Pira.back().p;
         if(enpila != Pira.back().h){
         RES[i] = max(RES[j], RES[i]);
         RES[j] = max(RES[j], RES[i]);
         } 
         else {
         RES[i] = max(RES[j], RES[i]);
         }
         enpila = Pira.back().h;
         Pira.pop_back();
        }
        enpila = -100000000000;
        if(!Pira.empty() && h <= Pira.back().h){
         j = Pira.back().p;
         RES[j] = max(RES[j], RES[i]);
         RES[i] = max(Pira.back().r, RES[i]);
        }        
        aux.h = h;
        aux.r = r;
        aux.p = i;
        Pira.push_back(aux);
    }
    if(!Pira.empty()){
        j = Pira.back().p;
        h = Pira.back().h;
        r = Pira.back().r;
        Pira.pop_back();
    }
    while(!Pira.empty()){
        i = Pira.back().p;
        if(h == Pira.back().h){
        RES[i] = max(Pira.back().r, RES[i]);
        RES[j] = max(r, RES[j]);
            if(RES[i] > RES[j]){ 
               j = Pira.back().p;
               h = Pira.back().h;
               r = Pira.back().r;
            }        
        }
        else { 
         temp2 = Pira.back().r;
         RES[j] = max(RES[j], temp2);
         RES[i] = max(RES[i], RES[j]);
         j = Pira.back().p;
         h = Pira.back().h;
         r = Pira.back().r;
        }
        Pira.pop_back();
    }
    for(i = 1;i <= n; i++) cout << RES[i] << " ";    
    return 0;
}
