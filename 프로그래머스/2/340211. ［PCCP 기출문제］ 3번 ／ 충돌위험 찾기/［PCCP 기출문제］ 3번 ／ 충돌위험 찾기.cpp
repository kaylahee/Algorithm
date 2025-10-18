    // n개의 포인트 (1~n까지의 서로 다른 번호 가짐)
    // 정해진 운송 경로 있음 (m개)
    // x대, 모든 로봇은 0초에 동시 출발
    // 1초마다 상하좌우 방향으로 이동 가능

    // 다음 포인트로 이동할 때는, 항상 최단 경로로 이동하며
    // 최단 경로가 여러 가지일 경우, r좌표가 변하는 이동을 c좌표가 변하는 이동보다 먼저 한다.
    // 상하좌우 순으로 가면 될듯

    // 마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어난다.
    // 로봇이 물류 센터를 벗어나는 경로는 고려하지 않는다.

    // 최단 경로는 bfs로 구현
    // 동시에 움직이기에 바로 움직여서는 안됨

    #include <iostream>
    #include <string>
    #include <vector>
    #include <set>
    #include <map>

    using namespace std;

    int map[101][101];

    std::vector<std::pair<int, int>> robot_path[101];
    void make_segment_path(int sy, int sx, int ey, int ex, std::vector<std::pair<int, int>>& segment){    
        int ny = sy;
        int nx = sx;
        
        while (ny < ey){
            ny += 1;
            segment.push_back({ny, nx});
        }
        while (ny > ey){
            ny -= 1;
            segment.push_back({ny, nx});
        }
        while (nx < ex){
            nx += 1;
            segment.push_back({ny, nx});
        } 
        while (nx > ex){
            nx -= 1;
            segment.push_back({ny, nx});
        }
    }

    int solution(vector<vector<int>> points, vector<vector<int>> routes) {
        std::map<int, std::pair<int, int>> point_coords;
        for (int i = 0; i < points.size(); i++){
            int y = points[i][0];
            int x = points[i][1];

            point_coords[i + 1] = {y, x};
        }
        
        int robotCnt = routes.size();
        std::vector<std::vector<std::pair<int, int>>> robot_full_paths(robotCnt);
        for (int i = 0; i < robotCnt; i++){
            std::vector<int> robot_route_points = routes[i];
            robot_full_paths[i].push_back(point_coords[robot_route_points[0]]);
            
            for (int j = 0; j < robot_route_points.size() - 1; j++){
                int st = robot_route_points[j];
                int en = robot_route_points[j + 1];
                
                std::vector<std::pair<int, int>> segment;
                int stY = point_coords[st].first;
                int stX = point_coords[st].second;
                int enY = point_coords[en].first;
                int enX = point_coords[en].second;

                make_segment_path(stY, stX, enY, enX, segment);

                robot_full_paths[i].insert(robot_full_paths[i].end(), segment.begin(), segment.end());
            }
        }

        std::vector<std::pair<int, int>> collision_points;
        int max_time = 0;
        for (int i = 0; i < robotCnt; i++){
            if (robot_full_paths[i].size() > max_time){
                max_time = robot_full_paths[i].size();
            }
        }

        for (int t = 0; t < max_time; t++){
            std::map<std::pair<int, int>, int> locAtt;
            
            for (int i = 0; i < robotCnt; i++){
                if (t < robot_full_paths[i].size()){
                    std::pair<int, int> curPos = robot_full_paths[i][t];
                    locAtt[curPos]++;
                }
            }
            
            for (auto [pos, cnt] : locAtt){
                if (cnt >= 2){
                    collision_points.push_back(pos);
                }
            }
        }
        
        int answer = collision_points.size();
        return answer;
    }