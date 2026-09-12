#include "platform.h"

#include "utils/graphics_util.h"
#include "resource_manager.h"
#include "camera.h"

namespace PlantsVs {
void Platform::onDraw() const {
    const Vector2& pos_camera = GetCamera().GetPosition();
    putimage_alpha_center(img_platform_, static_cast<int>(position_.x - pos_camera.x), static_cast<int>(position_.y - pos_camera.y));
}

PlatformLarge::PlatformLarge(const Point2D& position) : Platform(position) {
    img_platform_ = GetResourceManager().GetImage("img_platform_large");
    shape_.y = position.y - 141.f; // 平台的y坐标
    shape_.left = position.x - 488.f; // 平台的左边界
    shape_.right = position.x + 488.f; // 平台的右边界
}

PlatformSmall::PlatformSmall(const Point2D& position) : Platform(position) {
    img_platform_ = GetResourceManager().GetImage("img_platform_small");
    shape_.y = position.y; // 平台的y坐标
    shape_.left = position.x - 84.f; // 平台的左边界
    shape_.right = position.x + 84.f; // 平台的右边界
}
}