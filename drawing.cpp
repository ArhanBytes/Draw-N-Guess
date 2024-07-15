#include <QtWidgets>
#include "drawing.h"

// Constructor for the Drawing class
Drawing::Drawing(QWidget *parent)
    : QWidget(parent), scribbling(false), myPenWidth(1), myPenColor(Qt::blue)
{
    setAttribute(Qt::WA_StaticContents);
}

// Set the pen color
void Drawing::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

// Set the pen width
void Drawing::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

// Clear the image
void Drawing::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

// Handle mouse press events
void Drawing::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

// Handle mouse move events
void Drawing::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling) {
        drawLineTo(event->pos());
    }
}

// Handle mouse release events
void Drawing::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

// Paint the widget
void Drawing::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

// Handle resize events
void Drawing::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

// Draw a line from the last point to the specified end point
void Drawing::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

// Resize the image
void Drawing::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
