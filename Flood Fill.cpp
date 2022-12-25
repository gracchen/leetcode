/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        int srcColor = image[sr][sc];
        int r = image.size() - 1;
        int c = image[0].size() - 1;
        bool checkHoriz = c; //if not one block wide (zero), check. 
        bool checkVert = r; //if not one block tall (zero), check. 
        /*for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << image[i][j] << " ";
            cout << endl;
        }*/

        stack<pair<size_t,size_t>> toDo;
        toDo.push({sr,sc});
        image[sr][sc] = color; //fill
        while (!toDo.empty())
        {
            size_t rC = toDo.top().second;
            size_t rR = toDo.top().first;
            toDo.pop();
            //cout << curr.first << " " << curr.second << endl;
            if (checkHoriz)
            {
                if (rC < c && image[rR][rC+1] == srcColor)  //rC cannot already be end of row
                {
                    image[rR][rC+1] = color; //fill right neighbor
                    toDo.push({rR, rC+1});
                }
                if (rC && image[rR][rC-1] == srcColor)  //rC must be positive
                {
                    image[rR][rC-1] = color; //fill left neighbor
                    toDo.push({rR,rC-1});
                }
            }
            if (checkVert)
            {
                if (rR < r && image[rR+1][rC] == srcColor)  //rR cannot already be end of row
                {
                    image[rR+1][rC] = color; //fill upper neighbor
                    toDo.push({rR+1, rC});
                }
                if (rR && image[rR-1][rC] == srcColor)  //rR must be positive
                {
                    image[rR-1][rC] = color; //fill lower neighbor
                    toDo.push({rR-1,rC});
                }
            }
        }
        return image;
    }
};
