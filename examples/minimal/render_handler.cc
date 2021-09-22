#include "render_handler.h"
#include <iostream>
#include "include/cef_render_handler.h"

namespace minimal {

RenderHandler::RenderHandler() {
  std::cout << "[RenderHandler]" << std::endl;
};
void RenderHandler::OnPaint(CefRefPtr<CefBrowser> browser,
                            CefRenderHandler::PaintElementType type,
                            const CefRenderHandler::RectList& dirtyRects,
                            const void* buffer,
                            int width,
                            int height) {
  // int* charBuffer = (int*)buffer;
  std::cout << "onpaint " << width << " " << height << std::endl;
  // for (int i = 0; i < 4 * 5; i++) {
  //   std::cout << charBuffer[i] << " ";
  // }
  FILE* rendered_file;
  rendered_file = fopen("img", "wb");
  fwrite(buffer, width * height * 4, sizeof(buffer), rendered_file);
  fclose(rendered_file);
  // exit(0);
  std::cout << std::endl;
};

void RenderHandler::OnAcceleratedPaint(
    CefRefPtr<CefBrowser> browser,
    CefRenderHandler::PaintElementType type,
    const CefRenderHandler::RectList& dirtyRects,
    void* shared_handle) {
  std::cout << "OnAcceleratedPaint" << std::endl;
}

bool RenderHandler::GetRootScreenRect(CefRefPtr<CefBrowser> browser,
                                      CefRect& rect) {
  std::cout << "[GetRootScreenRect]" << std::endl;
  rect.Set(0, 0, 1920, 1080);
  return true;
}

void RenderHandler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) {
  std::cout << "[GetViewRect]" << std::endl;
  rect.Set(0, 0, 1920, 1080);
}
}  // namespace minimal