//#include <iostream>
//#include <vector>
//
//// 처음 블록 형태 수정 X
//int origin[4][4];
//
//// 처음 블록 형태
//int block[4][4];
//
//// 회젼된 블록 형태
//int rotated[4][4];
//
//// 바뀐 블록 형태
//int tmp[4][4];
//
//// 검은 판
//int black[10][10];
//
//std::vector<std::vector<std::vector<int>>> block_state;
//
//void left();
//void up();
//
//void originTotmp() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            tmp[i][j] = origin[i][j];
//        }
//    }
//}
//
//void blockTotmp() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            tmp[i][j] = block[i][j];
//        }
//    }
//}
//
//void tmpToblock() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            block[i][j] = tmp[i][j];
//        }
//    }
//}
//
//void rotatedTotmp() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            tmp[i][j] = rotated[i][j];
//        }
//    }
//}
//
//void print() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            std::cout << tmp[i][j];
//        }
//        std::cout << "\n";
//    }
//}
//
//void copyTmpToVector() {
//    std::vector<std::vector<int>> state(4, std::vector<int>(4));
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            state[i][j] = tmp[i][j];
//    block_state.push_back(state);
//}
//
//void rotate90_once() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            rotated[i][j] = tmp[3 - j][i];
//        }
//    }
//    rotatedTotmp();
//}
//
//bool isSameBlock(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b) {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (a[i][j] != b[i][j]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void prepareRotations() {
//    block_state.clear();
//    // 초기 상태 저장
//    copyTmpToVector();
//
//    for (int r = 1; r < 4; r++) {
//        rotate90_once();
//        tmpToblock();
//        left();
//        tmpToblock();
//        up();
//
//        std::vector<std::vector<int>> new_state(4, std::vector<int>(4));
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                new_state[i][j] = tmp[i][j];
//            }
//        }
//        
//        bool istwo = false;
//        for (auto& prev : block_state) {
//            if (isSameBlock(prev, new_state)) {
//                istwo = true;
//                break;
//            }
//        }
//
//        if (!istwo) {
//            block_state.push_back(new_state);
//        }
//    }
//}
//
//void up() {
//    int k = 0;
//    bool candelete = true;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (block[i][j] != 0) {
//                candelete = false;
//                break;
//            }
//
//        }
//        if (candelete) {
//            k++;
//        }
//    }
//
//    while (k--) {
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                tmp[i][j] = block[(i + 1) % 4][j];
//            }
//        }
//        tmpToblock();
//    }
//}
//
//void left() {
//    int k = 0;
//    bool candelete = true;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (block[j][i] != 0) {
//                candelete = false;
//                break;
//            }
//
//        }
//        if (candelete) {
//            k++;
//        }
//    }
//
//    while (k--) {
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                tmp[i][j] = block[i][(j + 1) % 4];
//            }
//        }
//        tmpToblock();
//    }
//}
//
//bool isValid(int y, int x) {
//    if (y < 0 || y >= 10 || x < 0 || x >= 10) {
//        return false;
//    }
//    return true;
//}
//
//int cnt;
//
//bool findBlock(int y, int x, std::vector<std::vector<int>>block) {
//    int cnt_tmp = 0;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (isValid(i + y, j + x) && block[i][j] == 3 && black[i + y][j + x] == 0) {
//                cnt_tmp++;
//            }
//        }
//    }
//
//    if (cnt == cnt_tmp) {
//        return true;
//    }
//    return false;
//}
//
//int res2 = 0;
//
//int main_Imp_10() {
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            char a;
//            std::cin >> a;
//
//            if (a == '$') {
//                block[i][j] = 3;
//                cnt++;
//            }
//            else {
//                block[i][j] = 0;
//            }
//        }
//    }
//    up();
//    left();
//
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            origin[i][j] = block[i][j];
//        }
//    }
//
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            char a;
//            std::cin >> a;
//
//            if (a == '#') {
//                black[i][j] = 1;
//            }
//            else {
//                black[i][j] = 0;
//            }
//        }
//    }
//    blockTotmp();
//    //print();
//
//    prepareRotations();
//
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            for (auto& state : block_state) {
//                if (findBlock(i, j, state)) {
//                    res2++;
//                }
//            }
//        }
//    }
//
//    std::cout << res2 << "\n";   
//
//    return 0;
//}