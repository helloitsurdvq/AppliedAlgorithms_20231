#include <iostream>
#include <queue>
#include <set>

struct State {
    int x, y, steps;
    State(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps) {}
};

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minStepsToReachC(int a, int b, int c) {
    if (c % gcd(a, b) != 0 || (c > std::max(a, b))) {
        return -1; // No solution
    }

    std::queue<State> q;
    std::set<std::pair<int, int>> visited;

    q.push(State(0, 0, 0));
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.x == c || current.y == c) {
            return current.steps;
        }

        // Fill jug 1
        if (visited.insert({a, current.y}).second) {
            q.push(State(a, current.y, current.steps + 1));
        }

        // Fill jug 2
        if (visited.insert({current.x, b}).second) {
            q.push(State(current.x, b, current.steps + 1));
        }

        // Pour from jug 1 to jug 2
        int pour = std::min(current.x, b - current.y);
        if (visited.insert({current.x - pour, current.y + pour}).second) {
            q.push(State(current.x - pour, current.y + pour, current.steps + 1));
        }

        // Pour from jug 2 to jug 1
        pour = std::min(current.y, a - current.x);
        if (visited.insert({current.x + pour, current.y - pour}).second) {
            q.push(State(current.x + pour, current.y - pour, current.steps + 1));
        }

        // Empty jug 1
        if (visited.insert({0, current.y}).second) {
            q.push(State(0, current.y, current.steps + 1));
        }

        // Empty jug 2
        if (visited.insert({current.x, 0}).second) {
            q.push(State(current.x, 0, current.steps + 1));
        }
    }

    return -1; // No solution found
}

int main() {
    // Input
    int a, b, c;
    std::cin >> a >> b >> c;

    // Output
    int result = minStepsToReachC(a, b, c);
    std::cout << result << std::endl;

    return 0;
}
