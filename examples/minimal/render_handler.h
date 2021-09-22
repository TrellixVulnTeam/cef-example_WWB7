#pragma once
#include <iostream>
#include "include/cef_render_handler.h"

namespace minimal {

class RenderHandler : public CefRenderHandler {
 public:
  RenderHandler();
  void OnPaint(CefRefPtr<CefBrowser> browser,
               PaintElementType type,
               const RectList& dirtyRects,
               const void* buffer,
               int width,
               int height) override;

  void OnAcceleratedPaint(CefRefPtr<CefBrowser> browser,
                          CefRenderHandler::PaintElementType type,
                          const CefRenderHandler::RectList& dirtyRects,
                          void* shared_handle) override;

  void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
  bool GetRootScreenRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;

 private:
  IMPLEMENT_REFCOUNTING(RenderHandler);
};
}  // namespace minimal
