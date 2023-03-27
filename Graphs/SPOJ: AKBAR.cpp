#include <bits/stdc++.h>
using namespace std;


bool  BFS(int s,vector<vector<int>> &adj_list,vector<int> &Protected, int S, vector<bool> & visited){
	Protected[s]++;
	if (Protected[s] > 1) {
		return false;
	}
	queue<pair<int, int>> q;
	visited[s] = true;
	q.push({s, S});
	while(!q.empty()) {
		int node = q.front().first;
		int strength_left = q.front().second;
		q.pop();
		if (strength_left <= 0) {
			continue;
		}
		for(auto adj_node:adj_list[node]){ 
			if(visited[adj_node]==false){ 
				Protected[adj_node]++;
				q.push({adj_node, strength_left-1});
				visited[adj_node] = true; 
			}    
		}
	}
	return true;
}

void solve(){
   int n,r,m;cin>>n>>r>>m;
   vector<vector<int>> adj_list(n+1);
   vector<int> Protected(n+1,0);
   vector<bool> visited(n+1,false);
   for(int i=0;i<r;i++){
    int A,B;cin>>A>>B;
    adj_list[A].push_back(B);
    adj_list[B].push_back(A);
   }
   vector<int> strength(n+1,-1);
   for(int i=0;i<m;i++){
       int K,S;cin>>K>>S;
       strength[K] = S;
   }
	 bool flag = true;
	 for(int i=1;i<=n;i++){
		 if(strength[i] >= 0) {
			 flag = BFS(i,adj_list,Protected,strength[i],visited);
			 if (!flag) {
				 break;
			 }
		 }
		 /* for(int s=0;s<=n;s++) visited[s] = false; */
	 }
	 /* for(int i=1;i<=n;i++){ */
		 /* cout << Protected[i] << "\n"; */
	 /* } */
	 if (!flag) {
		 cout << "No\n";
		 return;
	 } else {
		 for(int i=1;i<=n;i++){
			 if(visited[i] == false) {
				 flag = false;
				 break;
			 }
		 }
	 }
	 if (flag) {
		 cout << "Yes\n";
	 } else {
		 cout << "No\n";
	 }
   return;
}


int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    int T;cin>>T;
    while(T--){
     solve();
		 /* if(T)cout << "\n"; */
    }
    return 0;
}

