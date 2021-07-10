#include "SBDL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
//prototypes
using namespace std;
void makerand_fixed();void makerand_animated();void loadingTexture();void running();void movation();void fall();
void crashbalcony();void crashspike();void crashbubble();void crashbird_m();void playgame();void set_defult();
void crashfox_m();void crashblade_m();void first_menu();void puase_menu();void end_menu();


Texture background,bubble,run_r[2][3],run_l[2][3],jumpr[2][4],jumpl[2][4],
run_r_1,run_r_2,run_r_3,jump_1,jump_2,jump_3,jump_4,run_l_1,run_l_2,run_l_3,
brun_r_1,brun_r_2,brun_r_3,bjump_1,bjump_2,bjump_3,bjump_4,brun_l_1,brun_l_2,brun_l_3,
balcony,balcony2,falling,falling2,spike,spike2,bird1,bird2,bird3,bird[3],fox1,fox2,fox3,fox4,fox5,fox6,fox[6],
rope,blade1,blade2,thrower,blade[2],score,back,PLAYBTN,music_btn,sound_btn,off_slash,again,gameover_panel,home,
PAUSEMENU,QUITBTN,backk;

Sound *jump,*falll;
Music *music;
Font *font;
SDL_Rect backgroundRect,bubbleRect[100],playerRect,run_rRect[2],run_lRect[2],jump_rRect[2][4],jump_lRect[2][4],rope2Rect,
balconyRect[100],balcony2Rect[100],fallingRect,spikeRect[100],spike2Rect[100],birdRect,foxRect,ropeRect,bladeRect,throwerRect,
PLAYBTNRect,sound_btnRect,music_btnRect,off_slash1Rect,off_slash2Rect,againRect,homeRect,play_pauseRect,QUITBTNRect;


int frame=1,jumpstate=0,bubblestate=0,timebubble=0,animate_frame=0,barrier_type=3,point=0,foxstate=1,gameswitch=0,fall_frame=0;
bool runningRight=true,GameOver=false,play_game_over_sound=true,music_on=true,sound_on=true,againn=true;
enum states{rightwall,leftwall,jumping}state;


void loadingTexture(){
    background=SBDL::loadTexture("assets/back1.png");
    back=SBDL::loadTexture("assets/back2.png");
    backk=SBDL::loadTexture("assets/backk.png");
    PLAYBTN=SBDL::loadTexture("assets/PLAYBTN.png");
    music_btn=SBDL::loadTexture("assets/music_btn.png");
    sound_btn=SBDL::loadTexture("assets/sound_btn.png");
    off_slash=SBDL::loadTexture("assets/off_slash.png");
    again=SBDL::loadTexture("assets/again.png");
    gameover_panel=SBDL::loadTexture("assets/gameover_panel.png");
    home=SBDL::loadTexture("assets/home.png");
    PAUSEMENU=SBDL::loadTexture("assets/PAUSEMENU.png");
    QUITBTN=SBDL::loadTexture("assets/QUITBTN.png");
    bubble=SBDL::loadTexture("assets/bubble.png");
    run_r_1=SBDL::loadTexture("assets/1.png");
    run_r_2=SBDL::loadTexture("assets/2.png");
    run_r_3=SBDL::loadTexture("assets/3.png");
    run_l_1=SBDL::loadTexture("assets/4.png");
    run_l_2=SBDL::loadTexture("assets/5.png");
    run_l_3=SBDL::loadTexture("assets/6.png");
    jump_1=SBDL::loadTexture("assets/7.png");
    jump_2=SBDL::loadTexture("assets/8.png");
    jump_3=SBDL::loadTexture("assets/9.png");
    jump_4=SBDL::loadTexture("assets/10.png");

    brun_r_1=SBDL::loadTexture("assets/b1.png");
    brun_r_2=SBDL::loadTexture("assets/b2.png");
    brun_r_3=SBDL::loadTexture("assets/b3.png");
    brun_l_1=SBDL::loadTexture("assets/b4.png");
    brun_l_2=SBDL::loadTexture("assets/b5.png");
    brun_l_3=SBDL::loadTexture("assets/b6.png");
    bjump_1=SBDL::loadTexture("assets/b7.png");
    bjump_2=SBDL::loadTexture("assets/b8.png");
    bjump_3=SBDL::loadTexture("assets/b9.png");
    bjump_4=SBDL::loadTexture("assets/b10.png");
    balcony=SBDL::loadTexture("assets/balcony.png");
    balcony2=SBDL::loadTexture("assets/balcony2.png");
    falling=SBDL::loadTexture("assets/falling2.png");
    falling2=SBDL::loadTexture("assets/falling3.png");
    spike2=SBDL::loadTexture("assets/SPIKES2.png");
    spike=SBDL::loadTexture("assets/SPIKES.png");
    bird1=SBDL::loadTexture("assets/bird1.png");
    bird2=SBDL::loadTexture("assets/bird2.png");
    bird3=SBDL::loadTexture("assets/bird3.png");
    fox1=SBDL::loadTexture("assets/SQ1.png");
    fox2=SBDL::loadTexture("assets/SQ2.png");
    fox3=SBDL::loadTexture("assets/SQ3.png");
    fox4=SBDL::loadTexture("assets/1_1.png");
    fox5=SBDL::loadTexture("assets/2_2.png");
    fox6=SBDL::loadTexture("assets/3_3.png");
    rope=SBDL::loadTexture("assets/rope.png");
    blade1=SBDL::loadTexture("assets/bl1.png");
    blade2=SBDL::loadTexture("assets/bl2.png");
    thrower=SBDL::loadTexture("assets/thrower.png");
    font = SBDL::loadFont("assets/Azuki Regular.ttf", 100);


    backgroundRect={0,0,300,600};
    run_rRect[0]={235,400,35,70};//run_rRect[0]=defult  run_rRect[1]=bubble
    run_rRect[1]={230,400,50,70};
    run_lRect[0]={30,400,35,70};
    run_lRect[1]={20,400,50,70};
    jump_rRect[0][0]={190,400,80,70};
    jump_rRect[0][1]={130,400,80,70};
    jump_rRect[0][2]={70,400,80,70};
    jump_rRect[0][3]={10,400,80,70};
    jump_rRect[1][0]={190,400,80,70};
    jump_rRect[1][1]={130,400,80,70};
    jump_rRect[1][2]={70,400,80,70};
    jump_rRect[1][3]={10,400,80,70};
    jump_lRect[0][0]={10,400,80,70};
    jump_lRect[0][1]={700,400,80,70};
    jump_lRect[0][2]={130,400,80,70};
    jump_lRect[0][3]={190,400,80,70};
    jump_lRect[1][0]={10,400,80,70};
    jump_lRect[1][1]={700,400,80,70};
    jump_lRect[1][2]={130,400,80,70};
    jump_lRect[1][3]={190,400,80,70};
    birdRect={0,4,50,40};
    foxRect={30,100,80,30};
    ropeRect={30,120,240,50};
    rope2Rect={30,0,240,50};
    bladeRect={70,100,40,40};
    throwerRect={20,100,50,70};

    run_r[0][0]={run_r_1};
    run_r[0][1]={run_r_2};
    run_r[0][2]={run_r_3};
    run_r[1][0]={brun_r_1};
    run_r[1][1]={brun_r_2};
    run_r[1][2]={brun_r_3};
    run_l[0][0]={run_l_1};
    run_l[0][1]={run_l_2};
    run_l[0][2]={run_l_3};
    run_l[1][0]={brun_l_1};
    run_l[1][1]={brun_l_2};
    run_l[1][2]={brun_l_3};
    jumpr[0][0]={jump_1};   jumpr[0][1]={jump_2};   jumpr[0][2]={jump_3};   jumpr[0][3]={jump_4};
    jumpr[1][0]={bjump_1};  jumpr[1][1]={bjump_2};    jumpr[1][2]={bjump_3};  jumpr[1][3]={bjump_4};
    jumpl[0][0]={jump_4};   jumpl[0][1]={jump_3};  jumpl[0][2]={jump_2}; jumpl[0][3]={jump_1};
    jumpl[1][0]={bjump_4};  jumpl[1][1]={bjump_3};    jumpl[1][2]={bjump_2};  jumpl[1][3]={bjump_1};
    fallingRect={150,410,50,50};
    bird[0]={bird1};    bird[1]={bird2};    bird[2]={bird3};
    fox[0]={fox1};    fox[1]={fox2};    fox[2]={fox3};    fox[3]={fox4};    fox[4]={fox5};    fox[5]={fox6};
    blade[0]={blade1};    blade[1]={blade2};

    falll=SBDL::loadSound("assets/fall.wav");
    jump=SBDL::loadSound("assets/jump.wav");
    music=SBDL::loadMusic("assets/music.ogg");
    PLAYBTNRect={120,410,60,60};
    sound_btnRect={30,410,60,60};
    music_btnRect={210,410,60,60};
    off_slash2Rect={30,410,0,60};
    off_slash1Rect={210,410,0,60};

    againRect={70,350,60,60};
    homeRect={180,340,70,70};
    play_pauseRect={70,350,60,60};
    QUITBTNRect={110,195,80,40};


}
void makerand_fixed(){
    int bubble_x,bubble_high=0,balcony_high=0,balcony2_high=0,spike_high=0,spike2_high=0;
    for(int i=0;i<100;i++,bubble_high+=800,balcony_high+=2000,balcony2_high+=2000,spike2_high+=2000,spike_high+=2000){
        //bubble
        if(rand()%2==0){bubble_x=20;}else{bubble_x=230;}
        bubbleRect[i]={bubble_x,rand()%800-200-bubble_high,50,70};
        //balcony
        balconyRect[i]={0,rand()%2000-200-balcony_high,90,60};
        //balcony2
        balcony2Rect[i]={210,rand()%2000-200-balcony2_high,90,60};
        //spike
        spikeRect[i]={30,rand()%2000-200-spike_high,20,90};
        //spike2
        spike2Rect[i]={30,rand()%2000-200-spike2_high,20,90};
    }
}
void set_defult(){
    birdRect={0,4,50,40};
    foxRect={30,100,80,30};foxstate=1;
    ropeRect={30,120,240,50};
    rope2Rect={30,0,240,50};
    bladeRect={70,100,40,40};
    throwerRect={20,100,50,70};
}
void makerand_animated(){
    if(animate_frame==0 and frame%120==0){barrier_type=rand()%4+1;set_defult();}  //barrier_type : 1.bird   2.fox   3.blade   4.rope
    switch(barrier_type){
        case 1 :crashbird_m();animate_frame++;
                if(animate_frame==14){animate_frame=0;barrier_type=0;}
                break;
        case 2 :crashfox_m();animate_frame++;
                if(animate_frame==100){animate_frame=0;barrier_type=0;}
                break;
        case 3 :crashblade_m();animate_frame++;
            if(animate_frame==100){animate_frame=0;barrier_type=0;}
                break;
        case 4 :SBDL::showTexture(rope, rope2Rect);animate_frame++;rope2Rect.y+=5;
                if(animate_frame==120){animate_frame=0;barrier_type=0;}
                break;

    }
}
void running(){
    int i = frame % 3;
    if (state == rightwall) {playerRect=run_rRect[bubblestate];SBDL::showTexture(run_r[bubblestate][i],playerRect);}
    if (state == leftwall) {playerRect=run_lRect[bubblestate];SBDL::showTexture(run_l[bubblestate][i],playerRect);}
    if (state == jumping) {
        if (runningRight == true) { playerRect=jump_rRect[bubblestate][jumpstate];
            SBDL::showTexture(jumpr[bubblestate][jumpstate],playerRect);jumpstate++;}
        else if (runningRight == false) {playerRect=jump_lRect[bubblestate][jumpstate];
            SBDL::showTexture(jumpl[bubblestate][jumpstate],playerRect);jumpstate++;}
        if (jumpstate == 4) {jumpstate = 0;
            if (runningRight == true) {state = leftwall;runningRight = false;}
            else {state = rightwall;runningRight = true;}}}
    if (SBDL::keyPressed(SDL_SCANCODE_SPACE)){state = jumping;if(sound_on==true){SBDL::playSound(jump, 1);}}

}
void movation(){
    for (int j = 0; j < 100; j++)
    {bubbleRect[j].y += 5,balconyRect[j].y += 5;balcony2Rect[j].y += 5;
    spikeRect[j].y+=5;spike2Rect[j].y+=5;}
}
void fall(){
int i=frame%4;
if(i==0 or i==1){SBDL::showTexture(falling2,fallingRect);}
else {SBDL::showTexture(falling,fallingRect);}
fallingRect.y+=4;fall_frame++;
}
void crashbalcony(){
    for(int j=0;j<100;++j)
    {if (SBDL::hasIntersectionRect(balconyRect[j],playerRect))
    {if (bubblestate==0){GameOver=true;}
    else{bubblestate=0;balconyRect[j].w=0;}}
    if (SBDL::hasIntersectionRect(balcony2Rect[j], playerRect))
    {if (bubblestate==0){GameOver=true;}
        else{bubblestate=0;balcony2Rect[j].w=0;}}
    }}
void crashspike(){
    for(int j=0;j<100;++j)
    {if (SBDL::hasIntersectionRect(spikeRect[j],playerRect))
        {if (bubblestate==0){GameOver=true;}
            else{bubblestate=0;spikeRect[j].w=0;}}
        if (SBDL::hasIntersectionRect(spike2Rect[j], playerRect))
        {if (bubblestate==0){GameOver=true;}
            else{bubblestate=0;spike2Rect[j].w=0;}}
    }}
void crashbubble(){
    for(int j=0;j<100;++j){
        if (SBDL::hasIntersectionRect(bubbleRect[j],playerRect)) {
            bubblestate = 1;
            bubbleRect[j].w = 0;
            timebubble = 0;
        }}
    timebubble++;
    if (timebubble == 100) { bubblestate = 0; }//time for shiled on bubble=10s
}
void crashbird_m(){
    if (animate_frame<5){SBDL::showTexture(bird[frame%3], birdRect);}
    else{
    SBDL::showTexture(bird[frame%3], birdRect);
    if(SBDL::hasIntersectionRect(birdRect,playerRect))
        {
        if(state==jumping){point++;}
        else if(bubblestate==1){bubblestate=0;}
        else{ GameOver=true;}
        birdRect.w=0;
        }
    else
        {birdRect.x +=25;birdRect.y +=50;}
    }
}
void crashfox_m(){
    SBDL::showTexture(fox[foxstate], foxRect);
    SBDL::showTexture(rope, ropeRect);
    if(SBDL::hasIntersectionRect(foxRect,playerRect))
    {
        if(state==jumping){point++;}
        else if(bubblestate==1){bubblestate=0;}
        else{ GameOver=true;}
        foxRect.w=0;ropeRect.w=0;
    }
    else
    {switch(foxstate)
        {
        case 1:case 2:foxRect.x+=80;break;
        case 3:case 6:break;
        case 4:case 5:foxRect.x-=80;break;
        }
        foxRect.y+=5;ropeRect.y+=5;
    }
    foxstate++;if(foxstate>=6){foxstate=1;}
}
void crashblade_m(){
    SBDL::showTexture(thrower, throwerRect);
    SBDL::showTexture(blade[frame%2], bladeRect);
    if(SBDL::hasIntersectionRect(throwerRect,playerRect)){
        if(bubblestate==1){bubblestate=0;}
        else{ GameOver=true;}
        throwerRect.w=0;}
    if(SBDL::hasIntersectionRect(bladeRect,playerRect))
    {
        if(state==jumping){point++;}
        else if(bubblestate==1){bubblestate=0;}
        else{ GameOver=true;}
        bladeRect.w=0;
    }
    else
    {bladeRect.x +=10;bladeRect.y +=22;throwerRect.y+=5;}
}
void playgame(){
    SBDL::showTexture(background, backgroundRect);
    if (GameOver == true )
    { if(fall_frame<50){fall();}else{gameswitch=3;}
    if(play_game_over_sound==true)  if(sound_on==true){SBDL::playSound(falll, 1);play_game_over_sound=false;}}
    else {
        for (int j = 0; j < 100; ++j) {
            SBDL::showTexture(bubble, bubbleRect[j]);
            SBDL::showTexture(balcony, balconyRect[j]);
            SBDL::showTexture(balcony2, balcony2Rect[j]);
            SBDL::showTexture(spike2, spike2Rect[j]);
            SBDL::showTexture(spike, spikeRect[j]);
        }
        if (SBDL::keyPressed(SDL_SCANCODE_P)){gameswitch=2;}
        score = SBDL::createFontTexture(font,""+to_string(point),0,0,0);
        SBDL::showTexture(score, {130, 50, 30, 40});
        running();
        crashbubble();
        crashbalcony();
        crashspike();
        makerand_animated();
        movation();
    }
}
void first_menu(){
    SBDL::showTexture(back, {0,100,300,400});
    SBDL::showTexture(PLAYBTN,PLAYBTNRect);
            if(SBDL::mouseInRect(PLAYBTNRect) && SBDL::Mouse.clicked()){gameswitch=1;}
    SBDL::showTexture(sound_btn,sound_btnRect);
        SBDL::showTexture(off_slash,off_slash2Rect);
            if(SBDL::mouseInRect(sound_btnRect) && SBDL::Mouse.clicked())
                {if (sound_on==true)
                    {off_slash2Rect.w=60;sound_on=false;}
                else
                    {off_slash2Rect.w=0;sound_on=true;}}
    SBDL::showTexture(music_btn, music_btnRect);
        SBDL::showTexture(off_slash,off_slash1Rect);
            if(SBDL::mouseInRect(music_btnRect) && SBDL::Mouse.clicked())
                {if (music_on==true)
                    {off_slash1Rect.w=60;music_on=false;}
                else
                    {off_slash1Rect.w=0;music_on=true;SBDL::playMusic(music, -1);}}
}
void puase_menu(){
    SBDL::showTexture(backk, {0,0,300,600});
    SBDL::showTexture(PAUSEMENU, {0,200,300,400});
    SBDL::showTexture(home,homeRect);
    SBDL::showTexture(PLAYBTN,againRect);
    if(SBDL::mouseInRect(homeRect) && SBDL::Mouse.clicked()){gameswitch=0;state = rightwall;point=0;makerand_fixed();
        fall_frame=0;GameOver=false;fallingRect.y=410;play_game_over_sound=true;set_defult();}
    else if(SBDL::mouseInRect(play_pauseRect) && SBDL::Mouse.clicked()){gameswitch=1;}
}
void end_menu(){
    SBDL::showTexture(gameover_panel, {0,100,300,400});
    SBDL::showTexture(again,againRect);
    SBDL::showTexture(home,homeRect);
    SBDL::showTexture(QUITBTN,QUITBTNRect);
    score = SBDL::createFontTexture(font,""+to_string(point),0,0,0);
    SBDL::showTexture(score, {130, 130, 40, 40});
    if(SBDL::mouseInRect(homeRect) && SBDL::Mouse.clicked()){gameswitch=0;state = rightwall;point=0;makerand_fixed();
    fall_frame=0;GameOver=false;fallingRect.y=410;play_game_over_sound=true;set_defult();}
    else if(SBDL::mouseInRect(againRect) && SBDL::Mouse.clicked()){gameswitch=1;state = rightwall;point=0;
    makerand_fixed();fall_frame=0;GameOver=false;fallingRect.y=410;play_game_over_sound=true;set_defult();}
    else if(SBDL::mouseInRect(QUITBTNRect) && SBDL::Mouse.clicked()){againn=false;}
}
int main(int argc, char *argv[]) {
    const int window_width = 300;
    const int window_height = 600;
    SBDL::InitEngine("NINJUMP", window_width, window_height);
    const int FPS = 10; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame

    srand(time(NULL));
    loadingTexture();
    makerand_fixed();
    SBDL::playMusic(music, -1);

    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(againn==true) {
            if (music_on == false) { SBDL::stopMusic(); }
            switch (gameswitch) {
                case 0:first_menu();break;
                case 1:playgame();break;
                case 2:puase_menu();break;
                case 3:end_menu();break;
            }
            frame++;
        }
        else { SBDL::stopMusic(); }
        SBDL::updateRenderScreen();
        int elapsedTime = SBDL::getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - elapsedTime);

    }
}

/* gameswitch;
 * 0=first menu
 * 1=play game
 * 2=puase menu
 * 3=end menu
 * */
