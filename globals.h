#define MAX_SIZE 100
#define ROWS 28
#define COLS 52
extern bool gameover;
extern const int screenWidth;
extern const int screenHeight;
extern const int tileSize;
extern int score ;
extern int pacmanX;
extern int pacmanY;
extern int ghostrx;
extern int ghostry;
extern int ghostpx;
extern int ghostpy;
extern int ghostgx;
extern int ghostgy;
extern Color ghostg;
extern Color pacmanColor;
extern Color ghostr;
extern Color ghostp;
extern int startangle;
extern int endangle;
extern bool pelletExists;
extern int pacmanradius;
extern bool superPelletExists;
extern bool superPelletExists2;
extern int superPelletX, superPelletY;
extern bool superPelletVisible;
extern int superpelletcount;
extern float blinkTimer;
extern float blinkInterval;
extern bool pacman_exist;
extern bool screen;
extern float ghostConsumptionTimer;
extern bool canConsumeGhosts;
extern bool introPlayed;
extern int n;
extern int count;
extern Rectangle pauseButton;
extern char pauseButtonText[10];
extern bool isPaused;
extern bool ch;
extern int dRow[];
extern int dCol[];
extern int maze[28][52];

