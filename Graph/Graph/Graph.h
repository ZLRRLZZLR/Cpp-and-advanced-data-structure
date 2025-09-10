#pragma once
#include<map>
#include<vector>
#include<functional>
#include<string>
#include<queue>
#include"UnionFindSet.h"

using namespace std;


namespace matrix 
{
	template<class V,class W,W MAX_W = INT_MAX,bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
	public:

		Graph() = default;

		// 图的创建
		// 1、IO输入  -- 不方便测试,oj中更适合
		// 2、图结构关系写到文件，读取文件
		// 3、手动添加边
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);

			for (int i = 0; i < n; i++) {
				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_martix.resize(n);
			for (int i = 0; i < n; i++) {
				_martix[i].resize(n, MAX_W);
			}

		}

		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);

			if (it != _indexMap.end()) {
				return it->second;
			}
			else {

				cout << "不存在顶点" << ":" << v << endl;
				throw invalid_argument("顶点不存在");

				return -1;
			}
		}


		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_martix[srci][dsti] = w;

			//无向图
			if (Direction == false) {
				_martix[dsti][srci] = w;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);
			_AddEdge(srci, dsti, w);
		}

		void Print()
		{
			// 顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			// 矩阵
			// 横下标
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				//cout << i << " ";
				printf("%4d", i);
			}
			cout << endl;

			for (size_t i = 0; i < _martix.size(); ++i)
			{
				cout << i << " "; // 竖下标
				for (size_t j = 0; j < _martix[i].size(); ++j)
				{
					//cout << _matrix[i][j] << " ";
					if (_martix[i][j] == MAX_W)
					{
						//cout << "* ";
						printf("%4c", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d", _martix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _martix.size(); ++i)
			{
				for (size_t j = 0; j < _martix[i].size(); ++j)
				{
					if (i < j && _martix[i][j] != MAX_W)
					{
						cout << _vertexs[i] << "->" << _vertexs[j] << ":" << _martix[i][j] << endl;
					}
				}
			}

		}

		void BFS(const V& src)
		{
			size_t srci = GetVertexIndex(src);

			//队列和标记数组
			queue<int> q;
			vector<bool> visited(_vertexs.size(), false);

			q.push(srci);
			visited[srci] = true;

			int levelsize = q.size();

			int n = _vertexs.size();
			while (q.size()) {

				while (levelsize--) {
					int front = q.front();
					q.pop();
					cout << front << ":" << _vertexs[front] << " ";
					// 把front顶点的邻接顶点入队列
					for (int i = 0; i < n; i++) {
						if (_martix[front][i] != MAX_W && !visited[i]) {
							q.push(i);
							visited[i] = true;
						}
					}
				}

				cout << endl;
				levelsize = q.size();
			}
			cout << endl;
		}

		void _DFS(size_t srci, vector<bool>& visited)
		{
			cout << srci << ":" << _vertexs[srci] << endl;
			visited[srci] = true;


			// 找一个srci相邻的没有访问过的点，去往深度遍历
			for (int i = 0; i < _vertexs.size(); i++) {
				if (_martix[srci][i] != MAX_W && !visited[i]) {
					_DFS(i, visited);
				}
			}
		}

		void DFS(const V& src)
		{
			vector<bool> visited(_vertexs.size(), false);
			size_t srci = GetVertexIndex(src);
			_DFS(srci, visited);
		}

		struct Edge
		{
			size_t _srci;
			size_t _dsti;
			W _w;

			Edge(size_t srci,size_t dsti,W w)
				:_srci(srci)
				,_dsti(dsti)
				,_w(w)
			{}

			//边的比较直接比较权值
			bool operator>(const Edge& e) const
			{
				return _w > e._w;
			}

		};

		//最小生成树
		W Kruskal(Self& minTree)
		{
			size_t n = _vertexs.size();

			//最小数的初始化
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._martix.resize(n, nullptr);
			for (int i = 0; i < n; i++) {
				minTree._martix[i].resize(n, nullptr);
			}

			
			priority_queue<Edge, vector<Edge>, greater<Edge>> minque;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i < j && _martix[i][j] != MAX_W) {
						minque.emplace(i, j, _martix[i][j]);
					}
				}
			}

			//选边
			UnionFindSet ufs(n);

			W totalW = W();
			int size = 0;
			while(!minque.size()) {
				Edge min = minque.top();

				minque.pop();

				if (!ufs.InSet(min._srci, min._dsti)) {
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] <<":"<<min._w << endl;
					minTree._AddEdge(min._srci, min._dsti, min._w);
					ufs.Union(min._srci, min._dsti);
					size++;
					totalW += min._w;
				}
				else {
					cout << "构成环：";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
				}
			}

			//没有选到合适的n-1个边，无法生成最小生成树
			if (size != n - 1) {
				return W();
			}
			else {
				return totalW;
			}

		}

		W Prim(Self& minTree, const V& src)
		{
			size_t n = _vertexs.size();
			size_t srci = GetVertexIndex(src);

			//最小数的初始化
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._martix.resize(n);
			for (int i = 0; i < n; i++) {
				minTree._martix[i].resize(n, MAX_W);
			}


			vector<bool> X(n,false);
			vector<bool> Y(n,false);
			X[srci] = true;
			Y[srci] = false;

			// 从X->Y集合中连接的边里面选出最小的边
			priority_queue<Edge, vector<Edge>, greater<Edge>> minq;
			// 先把srci连接的边添加到队列中
			for (int i = 0; i < n; i++) {
				if (_martix[srci][i] != MAX_W) {
					minq.emplace(srci, i, _martix[srci][i]);
				}
			}

			cout << "Prim开始选边" << endl;
			size_t size = 0;
			W totalW = W();
			while (!minq.size()) {
				Edge min = minq.top();
				minq.pop();

				if (X[min._dsti]) {
					cout << "构成环:";
					cout << _vertexs[min._srci] << "->" << _vertexs[min._dsti] << ":" << min._w << endl;
				}

				else {
					minTree._AddEdge(min._srci, min._dsti, min._w);
					X[min._dsti] = true;
					Y[min._dsti] = false;
					size++;
					totalW += min._w;

					if (size == n - 1) {
						break;
					}

					for (int i = 0; i < n; i++) {
						if (_martix[min._dsti][i] != MAX_W && Y[i]) {
							minq.emplace(min._dsti,i, _martix[min._dsti][i]);
						}
					}

				}
			}

			if (size == n - 1) {
				return totalW;
			}
			else {
				return W();
			}

		}

		void PrintShortPath(const V& src, const vector<W>& dist, const vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();

			for (size_t i = 0; i < n; i++) {
				if (i != srci) {
					//找出i顶点的路径
					vector<int> path;
					size_t parenti = i;
					while (parenti != srci) {
						path.push_back(parenti);
						parenti = pPath[parenti];
					}
					path.push_back(srci);
					reverse(path.begin(), path.end());

					for (auto index : path) {
						cout << _vertexs[index] << "->";
					}
					cout << "权值和：" << dist[i] << endl;
				}
			}

		}

		//最短路径
		// 顶点个数是N  -> 时间复杂度：O（N^2）空间复杂度：O（N）
		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();
			dist.resize(n, MAX_W);
			pPath.resize(n, -1);

			dist[srci] = 0;
			pPath[srci] = srci;

			vector<bool> S(n, false);
			// 选最短路径顶点且不在S,更新其他路径
			int u = 0;
			W min = MAX_W;
			for (int i = 0; i < n; i++) {
				if (!S[i] && dist[i] < min) {
					u = i;
					min = dist[i];
				}
			}


				S[u] = true;

				// 松弛更新u连接顶点v  srci->u + u->v <  srci->v  更新
				for (int i = 0; i < n; i++) {
					if (!S[i] && _martix[u][i] != MAX_W
						&&_martix[u][i] + dist[u] < dist[i]) {
						dist[i] = _martix[u][i] + dist[u];
						pPath[i] = u;
					}
				}

		}

		// 时间复杂度：O(N^3) 空间复杂度：O（N）
		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t srci = GetVertexIndex(src);
			size_t n = _vertexs.size();

			// vector<W> dist,记录srci-其他顶点最短路径权值数组
			dist.resize(n, MAX_W);

			// vector<int> pPath 记录srci-其他顶点最短路径父顶点数组
			pPath.resize(n, -1);

			// 先更新srci->srci为缺省值
			dist[srci] = W();

			// 总体最多更新n轮
			for (int k = 0; k < n; k++) {
				// i->j 更新松弛
				bool update = false;
				cout << "更新第:" << k << "轮" << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						// srci -> i + i ->j
						if (_martix[i][j] != MAX_W && dist[i] != MAX_W && dist[i] + _martix[i][j] < dist[j]) {
							update = true;
							dist[j] = dist[i] + _martix[i][j];
							pPath[j] = i;
						}
					}
				}

				// 如果这个轮次中没有更新出更短路径，那么后续轮次就不需要再走了
				if (update == 0) {
					break;
				}
			}

			// 还能更新就是带负权回路
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					// srci -> i + i ->j
					if (_martix[i][j] != MAX_W && dist[i] != MAX_W && dist[i] + _martix[i][j] < dist[j]) {
						return false;
					}
				}
			}

			return true;
		}

		void FloydWarshall(vector<vector<W>>& vvDist, vector<vector<int>>& vvpPath)
		{
			size_t n = _vertexs.size();
			vvDist.resize(n);
			vvpPath.resize(n);

			// 初始化权值和路径矩阵
			for (int i = 0; i < n; i++) {
				vvDist[i].resize(n,MAX_W);
				vvpPath[i].resize(n,-1);
			}

			// 直接相连的边更新一下
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (_martix[i][j] != MAX_W)
					{
						vvDist[i][j] = _martix[i][j];
						vvpPath[i][j] = i;
					}

					if (i == j) {
						vvDist[i][j] = W();
					}
				}
			}


		// abcdef  a {} f ||  b {} c
		// 最短路径的更新i-> {其他顶点} ->j
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (vvDist[i][k] != MAX_W && vvDist[k][j] != MAX_W
							&& vvDist[i][k] + vvDist[k][j] < vvDist[i][j]) {
							vvDist[i][j] = vvDist[i][k] + vvDist[k][j];


							// 找跟j相连的上一个邻接顶点
							// 如果k->j 直接相连，上一个点就k，vvpPath[k][j]存就是k
							// 如果k->j 没有直接相连，k->...->x->j，vvpPath[k][j]存就是x

							vvpPath[i][j] = vvpPath[k][j];
						}
					}
				}
			}

			// 打印权值和路径矩阵观察数据
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					if (vvDist[i][j] == MAX_W)
					{
						//cout << "*" << " ";
						printf("%3c", '*');
					}
					else
					{
						//cout << vvDist[i][j] << " ";
						printf("%3d", vvDist[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;

			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = 0; j < n; ++j)
				{
					//cout << vvParentPath[i][j] << " ";
					printf("%3d", vvpPath[i][j]);
				}
				cout << endl;
			}
			cout << "=================================" << endl;

		}

	private:
		vector<V> _vertexs; //顶点集合
		map<V, int> _indexMap; //顶点映射下标
		vector<vector<W>> _martix; //邻接矩阵
	};
}






namespace link_table {

	template<class W>
	struct Edge {
		int _dsti; //目标点的下标
		W _w;	   //权值
		Edge<W>* _next;

		Edge(int dsti, const W& w)
			:_dsti(dsti)
			, _w(w)
			,_next(nullptr)
		{}

	};

	template<class V,class W,bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);

			for (int i = 0; i < n; i++) {

				_vertexs.push_back(a[i]);
				_indexMap[a[i]] = i;
			}

			_tables.resize(n);
		}

		size_t GetVertexIndex(const V& v)//找到数据的映射下标
		{
			auto it = _indexMap.find(v);

			if (it != _indexMap.end()) {
				return it->second;
			}
			else {

				throw invalid_argument("非法参数");
				return -1;
			}
		}

		//添加边，以头插的方式插入
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			//创建边：src->dst
			Edge* edge = new Edge(dsti, w);
			edge->_next = _tables[srci];
			_tables[srci] = edge;

			//无向图按双向图处理
			if (Direction == false) {
				//创建边：dst->src
				Edge* edge = new Edge(srci, w);
				edge->_next = _tables[dsti];
				_tables[dsti] = edge;
			}

		}

		void Print()
		{
			// 顶点
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _tables.size(); ++i)
			{
				cout << _vertexs[i] << "[" << i << "]->";
				Edge* cur = _tables[i];
				while (cur)
				{
					cout << "[" << _vertexs[cur->_dsti] << ":" << cur->_dsti << ":" << cur->_w << "]->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}

		private:
			vector<V> _vertexs;		//顶点集合
			map<V, int> _indexMap; //顶点映射下标
			vector<Edge*> _tables; //邻接表
		};

	void TestGraph1()
	{
		//Graph<char, int, true> g("0123", 4);
		//g.AddEdge('0', '1', 1);
		//g.AddEdge('0', '3', 4);
		//g.AddEdge('1', '3', 2);
		//g.AddEdge('1', '2', 9);
		//g.AddEdge('2', '3', 8);
		//g.AddEdge('2', '1', 5);
		//g.AddEdge('2', '0', 3);
		//g.AddEdge('3', '2', 6);

		//g.Print();

		string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<string, int, true> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}

}