#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<double>> convolution(const std::vector<std::vector<double>> &image, const std::vector<std::vector<double>> &kernel)
{
    int rows = image.size();
    int cols = image[0].size();
    int krows = kernel.size();
    int kcols = kernel[0].size();
    int kcenterX = kcols / 2;
    int kcenterY = krows / 2;
    std::vector<std::vector<double>> output(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sum = 0.0;
            for (int m = 0; m < krows; m++) {
                int mm = krows - 1 - m;
                for (int n = 0; n < kcols; n++) {
                    int nn = kcols - 1 - n;
                    int ii = i + (m - kcenterY);
                    int jj = j + (n - kcenterX);
                    if (ii >= 0 && ii < rows && jj >= 0 && jj < cols) {
                        sum += image[ii][jj] * kernel[mm][nn];
                    }
                }
            }
            output[i][j] = sum;
        }
    }
    return output;
}

std::vector<std::vector<double>> createRandomMatrix(int rows, int cols) {
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = dist(rng);
        }
    }
    return matrix;
}

int main() {
    std::vector<std::vector<double>> image = createRandomMatrix(3, 3);
    std::vector<std::vector<double>> kernel = createRandomMatrix(3, 3);
    std::vector<std::vector<double>> result = convolution(image, kernel);
    // print the image and kernel matrices
    // std::cout << "image matrix

    return 0; 
 }
