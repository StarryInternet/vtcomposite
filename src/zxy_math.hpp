#pragma once

#include <cmath>
#include <tuple>

namespace vtile {

template <typename T>
inline bool within_target(T const& vt, int z, int x, int y)
{
    if (vt.z > z) {
      return false;
    }
    std::size_t dz = static_cast<std::size_t>(z - vt.z);
    return ((x >> dz) == vt.x) && ((y >> dz) == vt.y);
}

inline std::tuple<int, int> displacement(int source_z, int tile_size, int z, int x, int y)
{
    int half_tile = tile_size >> 1u;
    int dx = 0;
    int dy = 0;
    int delta_z = z - source_z;
    for (int zi = delta_z; zi > 0; --zi)
    {
        half_tile <<= 1u;
        if (x & 1) {
          dx += half_tile;
        }
        if (y & 1) {
          dy += half_tile;
        }
        x >>= 1u;
        y >>= 1u;
    }
    return std::make_tuple(dx, dy);
}

} // namespace vtile
