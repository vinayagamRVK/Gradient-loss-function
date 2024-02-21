#include <stdio.h>

float gradw1(float x1, float x2, float y, float w1, float w2) {
    float new_w1= w1-(0.01*(2*(y-((w1*x1) +(w2*x2))*(-x1))));
    return new_w1;
}

float gradw2(float x1, float x2, float y, float w1, float w2) {
    float new_w2= w2-(0.01*(2*(y-((w1*x1) +(w2*x2))*(-x2))));
    return new_w2;
}

int main() {
    int i, n;
    float x1[5], x2[5], y[5], w1, w2, new_w1, new_w2, y_pred[5];

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the initial values of w1 and w2: ");
    scanf("%f %f", &w1, &w2);

    printf("Enter the input variables of x1, x2, and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f %f", &x1[i], &x2[i], &y[i]);
    }

    for (i = 0; i < n; i++) {
        new_w1 = gradw1(x1[i], x2[i], y[i], w1, w2);
        new_w2 = gradw2(x1[i], x2[i], y[i], w1, w2);
        y_pred[i] = (new_w1 * x1[i]) + (new_w2 * x2[i]);
        printf("w1: %.10f\tw2: %.10f\ty_pred: %.10f\n", new_w1, new_w2, y_pred[i]);
        w1 = new_w1;
        w2 = new_w2;
    }

    return 0;
}
