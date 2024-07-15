#ifndef DRAWING_H
#define DRAWING_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

// The Drawing class provides a widget for drawing with the mouse
class Drawing : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    Drawing(QWidget *parent = 0);

    // Sets the pen color to be used for drawing
    void setPenColor(const QColor &newColor);

    // Sets the pen width to be used for drawing
    void setPenWidth(int newWidth);

    // Gets the current pen color
    QColor penColor() const { return myPenColor; }

    // Gets the current pen width
    int penWidth() const { return myPenWidth; }

public slots:
    // Clears the image
    void clearImage();

protected:
    // Event handler for mouse press events
    void mousePressEvent(QMouseEvent *event) override;

    // Event handler for mouse move events
    void mouseMoveEvent(QMouseEvent *event) override;

    // Event handler for mouse release events
    void mouseReleaseEvent(QMouseEvent *event) override;

    // Event handler for paint events
    void paintEvent(QPaintEvent *event) override;

    // Event handler for resize events
    void resizeEvent(QResizeEvent *event) override;

private:
    // Draws a line from the last point to the specified end point
    void drawLineTo(const QPoint &endPoint);

    // Resizes the image to the specified size
    void resizeImage(QImage *image, const QSize &newSize);

    // Indicates whether the user is currently scribbling
    bool scribbling;

    // Holds the current pen width
    int myPenWidth;

    // Holds the current pen color
    QColor myPenColor;

    // Stores the image being drawn
    QImage image;

    // Stores the location of the last mouse event
    QPoint lastPoint;
};

#endif // DRAWING_H
