#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n, k, l;
		cin >> n >> k >> l;
		vector<int> d(n+2, -k);
		for (int i = 1; i <= n; ++i)
			cin >> d[i];

		set<tuple<int, int, bool>> mark;
		function<bool(int, int, bool)> go = [&](int pos, int tide, bool down)
		{
			if (pos > n) return true;

			if (mark.find({ pos, tide, down }) != mark.end())
				return false;

			mark.insert({ pos, tide, down });

			tide += down ? -1 : +1;
			if (tide == 0) down = false;
			if (tide == k) down = true;

			if (d[pos] + tide <= l && go(pos, tide, down))
				return true;
			if (d[pos + 1] + tide <= l && go(pos + 1, tide, down))
				return true;
			return false;
		};

		if (go(0, 0, false)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
