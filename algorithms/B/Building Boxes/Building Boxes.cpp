class Solution {
public:
    int minimumBoxes(int n) {
        
        // Find the biggest perfect pyramid
        uint32_t h = cbrt((long)6*n);
        uint32_t pyramid_box_num = h*(h+1)/2*(h+2)/3;   // /6 is split to /2 and /3 to avoid long to save space
        if ( pyramid_box_num > n ){
            h--;
            pyramid_box_num = h*(h+1)/2*(h+2)/3;            // /6 is split to /2 and /3 to avoid long to save space
        }
        
        // Calculate how many floor-touching boxes in the pyramid
        int pyramid_base_num = (h)*(h+1)/2;
        
        // Get the number of boxes to be added to the perfect pyramid
        n -= pyramid_box_num;
        
        // Find how many floor-touching boxes are added
        int z = sqrt(2*n);
        int max_box_added = z*(z+1)/2;
        if ( max_box_added < n)
            z++;
        
        return pyramid_base_num+z;
    }
};
