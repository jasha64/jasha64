import processing.core.PApplet;
import ddf.minim.AudioPlayer;
import ddf.minim.Minim;
import ddf.minim.analysis.FFT;

import java.io.File;

public class MinimMusicVisualizer extends PApplet
{
    private static String fileName;
    private static boolean isLoaded = false;

    // Play audio file
    private Minim minim;
    private AudioPlayer player;
    // Perform a Fast Fourier Transform (FFT) on the audio file
    private FFT fft;
    
    // Control variables
    private boolean repel = false;
    private boolean autopilot = true;
    private boolean display = true;
    private boolean voice = false;
    private boolean show_background_nodes = true;
    
    // Some display variables
    private int linesX = 15, linesY = 12;  // how many lines are there in the X direction / Y direction (used for drawing background dots) 
    private PVector distance;
    private color c;
    private Node[][] Nodes = new Node[linesX][linesY];
    private float sum = 0;
    private Fish jimmy = new Fish(); 
    
    // Subclasses to support display
    class Node
    {
      float xpos, ypos, speed, anchorx, anchory;
      Node (float x, float y, float s)
      {
        anchorx = x;
        anchory = y;
        ypos = y;
        xpos = x;
        speed = s;
      }
    }
    
    class Fish {
      float xpos, ypos, speed;
      Fish () { ypos = random(800*0.25, 800*0.75); xpos = random(1000*0.25, 1000*0.75); }
      void update() {
        xpos = lerp(xpos + random(sum/20) - sum/40, xpos, 0.5);
        ypos = lerp(ypos + random(sum/20) - sum/40, ypos, 0.5);
        if (ypos > height*0.75)      ypos = height*0.75;
        else if (xpos > width*0.75)  xpos = width*0.75;
        else if (xpos < width*0.25)  xpos = width*0.25;
        else if (ypos < height*0.25) ypos = height*0.25;
        }
    }

    @Override
    public void settings() { size(512, 400, P3D); }

    @Override
    public void setup()
    {
        background(0x000000);
        float stepsX = (width) / linesX, stepsY = (height) / linesY;
        for (int i = 0; i < linesX; i++)
          for (int j = 0; j < linesY; j++)
            Nodes[i][j] = new Node((i+0.5)*stepsX, (j+0.5)*stepsY, 2);
        
        selectInput("Choose the input audio file: ", "loadFile");
    }

    // Read audio file
    // @param file The input audio file as specified by user.
    public void loadFile(File file)
    {
        if (file == null) { println("No file selected. Exit. "); exit(); }
        else {
            fileName = file.getName();
            println("User Select: " + file.getAbsolutePath());

            // load file
            minim = new Minim(this);
            player = minim.loadFile(file.getAbsolutePath());
            fft = new FFT(player.bufferSize(), player.sampleRate());
            println(fileName + " is playing...");
            isLoaded = true;
            player.play();
        }
    }

    @Override
    public void stop()
    {
        if (player != null) { player.close(); minim.stop(); }
        super.stop();
    }

    @Override
    public void draw()
    {
        if (!isLoaded) return;

        background(0x000000);
        displayFileName();
        drawWaveform();
        drawFrequecySpectrum();
        if (show_background_nodes) drawBackground();
        
        if (display)
          text("[ s ] = Switch Simple/Full Display\n[ space ] = Change Form\n[ v ] = Pause/Play\n[ a ] = Auto/Manual\n[ h ] = Hide Instructions\n[ n ] = Next Song", 110, 60);
    }

    // Display file name in the center of the window
    public void displayFileName()
    {
        fill(119, 119, 119);
        textAlign(CENTER, CENTER);
        textMode(SHAPE);
        textSize(13);
        text(fileName, width / 2, height - 100);
    }

    // Draw a wave form of the left & right sound channel of the input audio file
    public void drawWaveform()
    {
        int circleX = width / 2;
        int circleY = 150;
        float a = 0;
        int slices = player.bufferSize();
        float angle = (2 * PI) / slices;
        for (int i = 0; i < slices - 1; i++)
        {
            // the left sound channel
            float left_x1 = circleX + cos(a) * (50 * player.left.get(i) + 75);
            float left_y1 = circleY + sin(a) * (50 * player.left.get(i) + 75);
            float left_x2 = circleX + cos(a + angle) * (50 * player.left.get(i + 1) + 75);
            float left_y2 = circleY + sin(a + angle) * (50 * player.left.get(i + 1) + 75);
            // the right sound channel
            float right_x1 = circleX + cos(a) * (50 * player.right.get(i) + 75);
            float right_y1 = circleY + sin(a) * (50 * player.right.get(i) + 75);
            float right_x2 = circleX + cos(a + angle) * (50 * player.right.get(i + 1) + 75);
            float right_y2 = circleY + sin(a + angle) * (50 * player.right.get(i + 1) + 75);
            a += angle;
            // draw circle
            stroke(0, 221, 119, 127);
            strokeWeight(2);
            line(left_x1, left_y1, left_x2, left_y2);
            stroke(0, 187, 255, 127);
            strokeWeight(2);
            line(right_x1, right_y1, right_x2, right_y2);
        }
        noStroke();
    }

    // FFT the audio file, draw spectrum
    public void drawFrequecySpectrum()
    {
        fft.forward(player.mix);

        noStroke();
        fill(238, 119, 0, 190);
        for(int i = 0; i < width/4; i++)
        {
            float b = fft.getBand(i);
            rect(i * 4, height - b, 4, b);
        }
    }
    
    public void drawBackground()
    {
      int coef = (repel ? 1 : -1);
      float last_sum = 0, scale = 0, intensity = 0, radius = 0;
      float maxMagnitude = 848.5281374;
      float magnitude = lerp(sum, last_sum, 0.7) / 2.5;
      
      for (int i = 0; i < linesX; i++) {
        for (int j = 0; j < linesY; j++) {
          if (autopilot) { jimmy.update(); distance = new PVector(Nodes[i][j].xpos - jimmy.xpos, Nodes[i][j].ypos - jimmy.ypos); }
          else distance = new PVector(Nodes[i][j].xpos - mouseX, Nodes[i][j].ypos - mouseY);
          scale = (1/distance.mag())*magnitude;
          fill(255);
          intensity = pow(1 - distance.mag()/(maxMagnitude), 5) / 5;
          radius = (intensity*magnitude);
          Nodes[i][j].xpos += coef*(distance.x*scale)/25;
          Nodes[i][j].ypos += coef*(distance.y*scale)/25;
          Nodes[i][j].xpos = lerp(Nodes[i][j].xpos, Nodes[i][j].anchorx, 0.05);
          Nodes[i][j].ypos = lerp(Nodes[i][j].ypos, Nodes[i][j].anchory, 0.05);
          if (radius > 50) {
            radius = 50;
          }
          if (radius < 2) {
            radius = 2;
          }
          c = color(170 + magnitude/2, magnitude*5, 255, 255);
          fill(c);
          stroke(c);
          ellipse(Nodes[i][j].xpos + coef*(distance.x*scale), Nodes[i][j].ypos + coef*(distance.y*scale), radius, radius);
        }
      }
     
      sum = 0; 
      for (int i = 0; i < player.bufferSize() - 1; i++)
      {
        if (voice) sum += 0;
        else sum += abs(player.left.get(i));
      }
      last_sum = sum;
    }

    // on key press, do corresponding operation
    public void keyPressed()
    {
      switch(key)
      {
        case ' ':  // change some display setting
          repel = !repel;
          break;
        
        case 'a':  // change some display setting
          autopilot = !autopilot;
          break;
        
        case 'v':  // play/pause
          voice = !voice;
          if (!voice) player.play();
          else player.pause();
          break;
        
        case 's':  // Hide background nodes for simpler display
          show_background_nodes = !show_background_nodes;
          break;
        
        case 'h':  // Hide the Hint Info in the upper-left of the window
          display = !display;
          break;
        
        case 'n':  // Let the user re-choose another input file 
          player.close(); minim.stop();
          selectInput("Choose the input audio file: ", "loadFile");
          break;
      }
    }

    public static void main(String[] args)
    {
        PApplet.main(new String[] {"MinimMusicVisualizer"});
    }
}
