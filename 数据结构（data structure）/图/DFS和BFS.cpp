
/*DFS algorithm*/

bool visited[MAX];

void DFS(Graph g, int v){
	visited[v] = true;	
	for(int w = firstVec(G,v); w>=0; w = nextVec(g,v,w))
		if(!visited[w]) DFS(g,w);
}

void DFSTraverse(Graph g){
	for(int v= 0;v<g.vecnum;++v) visited[v] = false; // init
	for(int v= 0;v<g.vecnum;++v)
		if(!visited[v]) DFS(g,v);
}

/*DFS非递归实现方法为利用栈来实现*/

/*BFS algorithm*/

void BFS(Graph g){
	for(int v=0; v<g.vecnum; ++v) visited[v] = false; //init
	
	queue<int> q;
	for(int v= 0; v<g.vecnum; ++v){
		if(!visited[v]){
			visted[v] = true;
			q.push(v);
			while(!q.empty()){
				int u = q.top();
				q.pop();
				for(int w = firstVec(G,u); w>=0; w = nextVec(g,u,w)){
					if(!visited[w]){
						visited[w] = true;
						q.push(w);
					} 
				}
			}
		}
	}
}
