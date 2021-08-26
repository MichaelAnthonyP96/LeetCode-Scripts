class Solution {
public:
    std::tuple<int, int, int> calculateDestination(std::string instructions)
    {
        int x = 0, y = 0;
        short direction = 0; // N - 0, E - 1, S - 2, W - 3
        for (auto& ch : instructions)
        {
            switch (ch) {
                case 'L':
                    direction = (direction + 3) % 4;
                    continue;
                case 'R':
                    direction = (direction + 1) % 4;
                    continue;
                case 'G':
                    if (direction == 0) ++y;
                    else if (direction == 1) ++x;
                    else if (direction == 2) --y;
                    else if (direction == 3) --x;
                    else throw std::runtime_error("invalid direction!");
            }
        }
        return std::make_tuple(x, y, direction);
    }
    
    bool isRobotBounded(string instructions) {
        auto result = calculateDestination(instructions);
        // std::cout << "x = " << std::get<0>(result) << " y = " << std::get<1>(result) << " direction = " << std::get<2>(result) << std::endl;
        if ((std::get<2>(result) != 0) || (!std::get<0>(result) && !std::get<1>(result)))
            return true;
        else
            return false;
    }
};