#include<bits/stdc++.h>

using namespace std;


/*
Approach:

Upon finding a white pixel, find all the neighbouring pixels which are white recursively. This is one white patch.
Keep storing and updating the topmost and the bottomost row encountered in a patch and similarly for leftmost and rightmost column.
Finally find centers and height/widths and prind the output.
complexity: O(N*M) 
*/


void bound(vector<vector<int> > &im, vector<vector<bool> > &vis, int i, int j, int &top, int& bottom, int& left, int& right, int n, int m)
{
	if (i<0 || i>n-1 || j<0 || j>m-1) return; // index out of range
	if (im[i][j]==0 || vis[i][j]) return; // black/visited pixel encountered.
	vis[i][j] = true;
	if (i<top) top = i;
	else if (i>bottom) bottom = i;
	if (j<left) left = j;
	else if (j>right) right = j;
	bound(im, vis, i+1, j, top, bottom, left, right, n, m);
	bound(im, vis, i-1, j, top, bottom, left, right, n, m);
	bound(im, vis, i, j+1, top, bottom, left, right, n, m);
	bound(im, vis, i, j-1, top, bottom, left, right, n, m);
	return;
}


int main()
{
	int n, m; cin >> n >> m; // This takes the number of rows and cols of the matrix respectively.
	vector<vector<int> > im(n, vector<int>(m, 0)); // This is the image in the form of matrix (using vector from c++)
	int a;
	for (int i = 0; i<n; ++i)
	{
		for (int j =0; j<m; ++j)
		{
			cin >> a;
			if (a) im[i][j]=a;
		}
	}
	vector<vector<bool> > vis(n, vector<bool>(m, false)); // An array to denote if a particular index has been visited.
	vector<vector<int> > boxes; // A vector which stores all the boxes' bounds.
	for (int i = 0; i<n; ++i)
	{
		for (int j =0;j<m; ++j)
		{
			if (im[i][j] && !vis[i][j])
			{
				int top=i, bottom=i, left=j, right=j;
				bound(im, vis, i, j, top, bottom, left, right, n, m); // pushing each bounding box in the answer.
				int center_row = (top+bottom)/2;
				int height = bottom-height+1;
				int center_col = (left+right)/2;
				int width = right-left+1;
				vector<int> temp(4);
				temp[0]=center_col; // <- center_x
				temp[1]=center_row; // <- center_y
				temp[2]=width;
				temp[3]=height;
				boxes.push_back(temp);
			}
		}
	}
	for (int x=0; x < boxes.size(); ++x) // printing all the bounding boxes in new lines
	{
		cout << "[";
		for (int y=0;y<4;++y) cout << boxes[x][y] << ",";
		cout << "]" << endl;
	}

	return 0;
}