#include "TextPrint.h"

TextPrint* TextPrint::instance()
{
    static TextPrint* tp = new TextPrint();
    return tp;
}

void TextPrint::print(std::string text)
{
    SDL_Surface* sur = TTF_RenderText_Blended(font, text.c_str(), fg);
    Rect c = { 0,0, std::min(sur->w, viewRect.w), std::min(sur->h, viewRect.h) };
    Rect r = { viewRect.x, viewRect.y, c.w, c.h };
    switch (format)
    {
    case TEXTFORMAT::CENTER:
        r.x += (viewRect.w - c.w) / 2;
        break;
    case TEXTFORMAT::RIGHT:
        r.x += viewRect.w - c.w;
        break;
    };
    SDL_Texture* tex = SDL_CreateTextureFromSurface(RENDER, sur);
    SDL_RenderCopy(RENDER, tex, &c, &r);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(sur);
}

TextPrint* TextPrint::setForeground(Color fg)
{
    this->fg = fg;
    return this;
}

TextPrint* TextPrint::setBackground(Color bg)
{
    this->bg = bg;
    return this;
}

TextPrint* TextPrint::setPosition(Point pos)
{
    viewRect.x = pos.x;
    viewRect.y = pos.y;
    return this;
}

TextPrint* TextPrint::setRenderRect(Rect size)
{
    viewRect = size;
    return this;
}

TextPrint* TextPrint::setTextFormat(TEXTFORMAT format)
{
    this->format = format;
    return this;
}

TextPrint* TextPrint::setFont(TTF_Font* font)
{
    this->font = font;
    return this;
}

TextPrint* TextPrint::setBorder(BORDER border)
{
    return this;
}

TextPrint::TextPrint() 
{
    fg = { 255,255,255,255 };
    bg = { 0,0,0,0 };
    font = nullptr;
    viewRect = { 0,0,0,0 };
    format = TEXTFORMAT::LEFT;
}
