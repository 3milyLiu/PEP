#ifndef SUDOKU_H
#define SUDOKU_H
#include<math.h>
#include "Searchable.h"

// TODO: Your Sudoku class goes here:
#include<vector>
#include<set>
using namespace std;
class Sudoku : public Searchable{
private:
    int size;
    vector<vector<set<int>>>board;
    vector<int> numbers;
    int root;
public:
    Sudoku(const int size):
    size(size),root(sqrt(size)){
        for (int r = 0; r < size; ++r){
            vector<set<int>>column;
            for (int c = 0; c < size; ++c){
                set<int> value;
                for (int i = 0; i < size; ++i){
                    value.insert(i+1);
                }
                column.push_back(value);
            }
            board.push_back(column);
            numbers.push_back(r);
        }
    }

    int getSquare(const int& row, const int& column)const{
        if(board[row][column].size() == 1){
            return *board[row][column].begin();
        }
        else{
            return -1;
        }
    }

    bool setSquare(const int& row, const int& column, const int& value){
        bool works = true;
        bool change = true;
        bool removeRow = true, removeColumn = true, removeBox = true;
        set<int>* values = & board[row][column];
        values->erase(values->begin(), values->end());
        values->insert(value);

        while(change){
            removeRow = false, removeColumn = false, removeBox = false;
            for(int rowValue = 0; rowValue < size; rowValue++){
                for(int columnValue = 0; columnValue < size; columnValue++){
                    int theSize = board[rowValue][columnValue].size();
                    if(theSize == 1){
                        change = true;
                        int deleteValue = getSquare(rowValue, columnValue);
                        for(int i = 0; i < size; i++){
                            set<int> *values = & board[rowValue][i];
                            if((values->size() != 1)){
                                if(values->find(deleteValue) != values->end()) {
                                    values->erase(values->find(deleteValue));
                                    removeRow = true;
                                }
                            }
                            values = & board[i][columnValue];
                            if((values->size() != 1)){
                                if (values->find(deleteValue) != values->end()) {
                                    values->erase(values->find(deleteValue));
                                    removeColumn = true;
                                }
                            }
                        }
                        int baser = (rowValue)-((rowValue)%root);
                        int basec = (columnValue)-((columnValue)%root);
                        for (auto ittr = numbers.begin() + baser; ittr != numbers.begin() + baser + root; ++ittr){
                            for (auto ittr2 = numbers.begin() + basec; ittr2 != numbers.begin() + basec + root; ++ittr2){
                                values = &board[*ittr][*ittr2];
                                if(values->size()!= 1){
                                    if(values->find(deleteValue) != values->end()){
                                        values->erase(values->find(deleteValue));
                                        removeBox = true;
                                    }
                                }
                            }
                        }
                        if(!removeRow && !removeColumn && !removeBox){
                            change = false;
                        }
                    }
                    else if(theSize == 0){
                        works = false;
                        break;
                    }
                }
            }
        }
        if (check()){
            works = false;
        }
        return works;
    }

    bool check(){
        for (int i = 0; i < size; ++i){
            for (int x = 0; x < size - 1; ++x){
                for (int z = x+1; z < size; ++z){
                    if(board[i][x] == board[i][z] && getSquare(i, x) != -1){
                        return true;
                    }
                    if(board[x][i] == board[z][i] && getSquare(x, i) != -1){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    virtual bool isSolution()const override{
        bool solution = true;
        for(int i = 0; i < size; ++i){
            for(int x = 0; x < size; ++x){
                if(getSquare(i, x) == -1){
                    solution = false;
                }
            }
        }
        return solution;
    }

    virtual void write(ostream & o)const override{
        for (int i = 0; i < size; ++i){
            for (int x = 0; x < size; ++x){
                if (board[i][x].size() == 1){
                    o << getSquare(i, x) << " ";
                }
                else{
                    o << "  ";
                }
            }
            o << endl;
        }
    }

    virtual vector<unique_ptr<Searchable>>successors()const override{
        vector<unique_ptr<Searchable>>successors;
        for (int i = 0; i < size; ++i) {
            for (int x = 0; x < size; ++x) {
                if (board[i][x].size() > 1) {
                    for(int z : board[i][x]) {
                        Sudoku* board = new Sudoku(*this);
                        if(board->setSquare(i,x,z)){
                            successors.emplace_back(board);
                        }
                        else{
                            delete board;
                        }
                    }
                    return successors;
                }
            }
        }
        return successors;
    }

    virtual int heuristicValue()const override{
        int squares = 0;
        for (int i = 0; i < size; ++i){
            for(int x = 0; x < size; ++x){
                if(board[i][x].size() != 1){
                    ++squares;
                }
            }
        }
        return squares;
    }

    void successors(){}

};

#endif
