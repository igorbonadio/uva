#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Block;

/******************************** Definitions ********************************/

class World {
public:
  World(int n);
  ~World();
  Block* GetBlock(int i);
  void SetWorldPosition(int i, Block* b);
  void Print();
private:
  vector<Block*> set_;
  vector<Block*> world_;
};

class Block {
public:
  Block(int n, World* world);
  
  int GetN();
  Block* GetAbove();
  void SetAbove(Block* b);
  Block* GetBelow();
  void SetBelow(Block* b);
  
  void MoveOnto(Block* b);
  void MoveOver(Block* b);
  void PileOnto(Block* b);
  void PileOver(Block* b);
  
private:
  void ReturnToInitialPositions_();
  Block* GetTop_();
  void JoinBlocks_(Block* b);
  bool ValidCommand_(Block* b);
  
  int n_;
  Block* above_;
  Block* below_;
  World* world_;
};

/****************************** Implementations ******************************/

World::World(int n) {
  for (int i; i < n; i++) {
    Block* b = new Block(i, this);
    set_.push_back(b);
    world_.push_back(b);
  }
}

Block* World::GetBlock(int i) {
  return set_[i];
}

void World::SetWorldPosition(int i, Block* b) {
  world_[i] = b;
}

void World::Print() {
  Block* block;
  int i = 0;
  vector<Block*>::iterator it;
  for (it = world_.begin(); it < world_.end(); it++) {
    block = *it;
    cout << i << ":";
    while (block) {
      cout << " " << block->GetN();
      block = block->GetAbove();
    }
    cout << endl;
    i++;
  }
}

World::~World() {
  vector<Block*>::iterator it;
  for (it = world_.begin(); it < world_.end(); it++)
    delete *it;
}

Block::Block(int n, World* world):n_(n),above_(0),below_(0),world_(world) {
};

int Block::GetN() {
  return n_;
}

Block* Block::GetAbove() {
  return above_;
}

void Block::SetAbove(Block* b) {
  above_ = b;
}

Block* Block::GetBelow() {
  return below_;
}

void Block::SetBelow(Block* b) {
  below_ = b;
}

void Block::ReturnToInitialPositions_() {
  Block* temp;
  Block* block = above_;
  while (block) {
    world_->SetWorldPosition(block->GetN(), block);
    block->SetBelow(0);
    temp = block;
    block = block->GetAbove();
    temp->SetAbove(0);
  }
  above_ = 0;
}

Block* Block::GetTop_() {
  Block* block = this;
  while (block->GetAbove()) {
    block = block->GetAbove();
  }
  return block;
}

void Block::JoinBlocks_(Block* b) {
  b->SetAbove(this);
  if(below_)
    below_->SetAbove(0);
  below_ = b;
  world_->SetWorldPosition(n_, 0);
}

void Block::MoveOnto(Block* b) {
  if(!ValidCommand_(b))
    return;
  ReturnToInitialPositions_();
  b->ReturnToInitialPositions_();
  JoinBlocks_(b);
}

void Block::MoveOver(Block* b) {
  if(!ValidCommand_(b))
    return;
  ReturnToInitialPositions_();
  JoinBlocks_(b->GetTop_());
}

void Block::PileOnto(Block* b) {
  if(!ValidCommand_(b))
    return;
  b->ReturnToInitialPositions_();
  JoinBlocks_(b);
}

void Block::PileOver(Block* b) {
  if(!ValidCommand_(b))
    return;
  JoinBlocks_(b->GetTop_());
}

bool Block::ValidCommand_(Block* b) {
  if (this == b)
    return false;
  Block* block = above_;
  while (block) {
    if (block == b)
      return false;
    block = block->GetAbove();
  }
  block = below_;
  while (block) {
    if (block == b)
      return false;
    block = block->GetBelow();
  }
  return true;
}

/*********************************** Main ************************************/

int main() {
  int n;
  cin >> n;
  World world(n);
  string cmd, where;
  int a, b;
  bool exit = false;
  while (!exit) {
    while (cin >> cmd >> a >> where >> b) {
      if (cmd == "move") {
        if (where == "onto") {
          world.GetBlock(a)->MoveOnto(world.GetBlock(b));
        }
        else if (where == "over") {
          world.GetBlock(a)->MoveOver(world.GetBlock(b));
        }
      }
      else if (cmd == "pile") {
        if (where == "onto") {
          world.GetBlock(a)->PileOnto(world.GetBlock(b));
        }
        else if (where == "over") {
          world.GetBlock(a)->PileOver(world.GetBlock(b));
        }
      }
    }
    if(cmd == "quit")
      exit = true;
  }
  world.Print();
  return 0;
}
