% ---------------------------------------------------------
% MATLAB Code: Polynomial Curve Fitting & Surface Reconstruction
% Target: Cylindrical Mug (Convex Surface Validation)
% ---------------------------------------------------------

% Step 1: Input transformed 2D spatial coordinates (x, y) in mm
% Data extracted from the 4-channel ToF sensor array
x_coords = [-82.14, -3.50, 3.50, 92.18];
y_coords = [102.44, 204.90, 176.33, 112.48];

% Step 2: Perform 2nd-order polynomial curve fitting (y = ax^2 + bx + c)
degree = 2;
coefficients = polyfit(x_coords, y_coords, degree);

% Extract individual mathematical coefficients
a = coefficients(1); % Quadratic coefficient (Shape classifier)
b = coefficients(2); % Linear coefficient
c = coefficients(3); % Constant coefficient

% Display coefficients in the command window for diagnostic review
fprintf('Quadratic Coefficient (a): %f\n', a);
fprintf('Linear Coefficient (b): %f\n', b);
fprintf('Constant Coefficient (c): %f\n', c);

% Step 3: Shape Classification Logic
if a < 0
    fprintf('Diagnostic Result: Target surface classified as CONVEX.\n');
else
    fprintf('Diagnostic Result: Target surface classified as CONCAVE/FLAT.\n');
end

% Step 4: Generate continuous profile points for plotting
x_fit = linspace(min(x_coords)-10, max(x_coords)+10, 100);
y_fit = polyval(coefficients, x_fit);

% Step 5: Plot the empirical data points and the reconstructed continuous surface
figure('Color', 'k'); % Set background to black for academic presentation
plot(x_fit, y_fit, 'b-', 'LineWidth', 2); % Reconstructed boundary
hold on;
plot(x_coords, y_coords, 'ro', 'MarkerSize', 8, 'LineWidth', 2); % Raw data points

% Formatting the graphical output
title('Object Shape Detection using Polynomial Fitting', 'Color', 'w', 'FontSize', 14);
xlabel('X Position (mm)', 'Color', 'w', 'FontSize', 12);
ylabel('Y Position (mm)', 'Color', 'w', 'FontSize', 12);
set(gca, 'Color', 'k', 'XColor', 'w', 'YColor', 'w');
legend('Fitted Object Surface', 'Sensor Data Points', 'TextColor', 'w', 'Location', 'south');
grid on;
hold off;