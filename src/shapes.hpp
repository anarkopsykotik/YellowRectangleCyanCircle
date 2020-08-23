#pragma once

#include "interface.hpp"
#include "types.hpp"

namespace YellowRectangleCyanCircle {
    class Circle : public IShape {
    public:
        Circle(int x, int y, int radius);

        void OnDraw(
            const CComPtr<ID2D1HwndRenderTarget>& target,
            const CComPtr<ID2D1SolidColorBrush>& brush,
            Point scale
        ) const override final;
    private:
        int x, y, radius;
    };

    class Rectangle : public IShape {
    public:
        Rectangle(Rect::Rect rect);

        void OnDraw(
            const CComPtr<ID2D1HwndRenderTarget>& target,
            const CComPtr<ID2D1SolidColorBrush>& brush,
            Point scale
        ) const override final;
    private:
        Rect::Rect rect;
    };
}
