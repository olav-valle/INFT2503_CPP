#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    string color_string() const {
      if (color == Color::WHITE)
        return "White";
      else
        return "Black";
    }
    string short_color_string() const {
      if (color == Color::WHITE)
        return "W";
      else
        return "B";
    }

    /// Return color and type of the chess piece
    virtual string type() const = 0;
    virtual string short_type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
  };

  class King : public Piece {
    // missing implementations
  public:
    King(Color color) : Piece(color) {}

    string type() const override {
      return color_string() + " king";
    }
    string short_type() const override {
      return short_color_string() + "_KI";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      return ((to_x >= 0 && to_x <= 7 && to_y >= 0 && to_y <= 7) && // check board boundary
              (abs(from_x - to_x) + abs(from_y - to_y) == 1))       // king moves 1 square any direction
                 ? true
                 : false;
    }
  };

  class Knight : public Piece {
    // missing implementations
  public:
    Knight(Color color) : Piece(color) {}

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      return ((to_x >= 0 && to_x <= 7 && to_y >= 0 && to_y <= 7) &&    // check board boundary
              ((abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) || // knight moves in "L" shape, 1+2 or 2+1
               (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2)))
                 ? true
                 : false;
    }

    string type() const override {
      return color_string() + " knight";
    }
    string short_type() const override {
      return short_color_string() + "_KN";
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  // Print current board
  void print_board_state() {
    cout << "    A    B    C    D    E    F    G    H" << endl
         << "  +----+----+----+----+----+----+----+----+" << endl;
    for (int y = 7; y >= 0; --y) {
      cout << y + 1 << " |";
      for (int x = 0; x <= 7; ++x) {
        if (auto &square = squares[x][y])
          cout << square->short_type() << "|";
        else
          cout << "    |";
      }
      cout << " " << y + 1 << endl
           << "  +----+----+----+----+----+----+----+----+" << endl;
    }
    cout << "    A    B    C    D    E    F    G    H" << endl
         << endl;
  }

  /// Move a chess piece if it is a valid move
  bool move_piece(const string &from, const string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            cout << piece_to->type() << " is being removed from " << to << endl;
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          } else {
            // piece in the from square has the same color as the piece in the to square
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_to = move(piece_from);
        return true;
      } else {
        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        return false;
      }
    } else {
      cout << "no piece at " << from << endl;
      return false;
    }
  }
};

int main() {
  ChessBoard board;

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  board.print_board_state();

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.print_board_state();
  board.move_piece("g8", "h6");
  board.print_board_state();
  board.move_piece("b1", "c3");
  board.print_board_state();
  board.move_piece("h6", "g8");
  board.print_board_state();
  board.move_piece("c3", "d5");
  board.print_board_state();
  board.move_piece("g8", "h6");
  board.print_board_state();
  board.move_piece("d5", "f6");
  board.print_board_state();
  board.move_piece("h6", "g8");
  board.print_board_state();
  board.move_piece("f6", "e8");
  board.print_board_state();
}
