#pragma once
#include<map>
#include<vector>
#include<functional>
#include<string>
#include<queue>

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

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " "; // 竖下标
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					//cout << _matrix[i][j] << " ";
					if (_matrix[i][j] == MAX_W)
					{
						//cout << "* ";
						printf("%4c", '*');
					}
					else
					{
						//cout << _matrix[i][j] << " ";
						printf("%4d", _matrix[i][j]);
					}
				}
				cout << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						cout << _vertexs[i] << "->" << _vertexs[j] << ":" << _matrix[i][j] << endl;
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

		}

		void DFS(const V& src)
		{
		}

		struct Edge
		{

		};

		W Kruskal(Self& minTree)
		{

		}

		W Prim(Self& minTree, const V& src)
		{

		}

		void PrintShortPath(const V& src, const vector<W>& dist, const vector<int>& pPath)
		{

		}

		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
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