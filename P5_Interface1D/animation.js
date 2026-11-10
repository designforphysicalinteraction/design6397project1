

class Animation {


    constructor() {
 
        this.numberOfFrames = 30;    // how many frames the animation has 
        this.pixels = 30;            // how wide the animation is
        
        // Multidimensional arrays in javascript are a bit silly
        // I recommend you watch this to understand what is happening next: https://www.youtube.com/watch?v=OTNpiLUSiB4
        this.animation = new Array(this.numberOfFrames);
       
        this.currentFrameCount = -1;       // this tracks what frame we are currently reading

        // The animation mimics an explosion and this variable tracks where the wave is in the display
        let k = 0;

        // Build up the array in this for loop
        for (let i = 0; i < this.numberOfFrames; i++) {
            
            // since javascript can't initialize a 2D array, we need to do this
            this.animation[i] = new Array(this.pixels);     
            
            // populate array with empty/black pixels
            for (let j = 0; j < this.pixels; j++) {
                this.animation[i][j] = color(0, 0, 0);
            }
        
        // Then populate array with animation
        
        // Start from the center
        let center = parseInt(this.pixels/2);
        
        // Animate to the right and left, but guard against out-of-bounds indices
        let rightIdx = k + center;
        let leftIdx = center - k;

        if (rightIdx >= 0 && rightIdx < this.pixels) { // make sure we don't go out of bounds
            this.animation[i][rightIdx] = color(255, 255, 0);
        }

        if (leftIdx >= 0 && leftIdx < this.pixels) { // make sure we don't go out of bounds
            this.animation[i][leftIdx] = color(255, 255, 0);
        }
        
        // Increment animation pixel
        k = k+1; 
    }

    }

    // This function advances animation to next frame and returns current frame number
    currentFrame() {

        this.currentFrameCount = this.currentFrameCount + 1; // advance to next frame

        if (this.currentFrameCount >= this.numberOfFrames) { // loop back to beginning
            this.currentFrameCount = 0;
        }

        return this.currentFrameCount;
    }

    // Returns one pixel at a time
    grabPixel(_index) {
        return this.animation[this.currentFrameCount][_index];
    }

}
