#ifndef QPYLONCAMERA_H
#define QPYLONCAMERA_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <pylon/PylonIncludes.h>

using namespace Pylon;

/**
 * @brief The QPylonImageEventHandler class
 * Handler the grabbed frame and convert it to QImage
 */
class QPylonImageEventHandler : public QObject, public CImageEventHandler
{
    Q_OBJECT
    friend class QPylonCamera;
public:
    using QObject::QObject;

    /**
     * @brief OnImageGrabbed
     * @param camera
     * @param ptrGrabResult
     */
    virtual void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& ptrGrabResult) override;

signals:
    void frameGrabbed(const QImage &frame);

private:
    static QImage resultToImage(const CGrabResultPtr& ptrGrabResult);
    static QImage toQImage(const CPylonImage &pylonImage);
};

/**
 * @brief The QPylonCamera class
 */
class QPylonCamera : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface *videoSurface READ videoSurface \
               WRITE setVideoSurface NOTIFY videoSurfaceChanged)
public:
    explicit QPylonCamera(QObject *parent = Q_NULLPTR);
    virtual ~QPylonCamera();

    inline bool isOpen() const {
        return mCamera != Q_NULLPTR && mCamera->IsOpen();
    }

    QAbstractVideoSurface *videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface *videoSurface);

signals:
    void videoSurfaceChanged();
    void captured(const QImage &imgs);

public slots:
    Q_INVOKABLE bool start();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void capture();

private slots:
    /**
     * @brief renderFrame
     * Render the grabbed frame for the video surface
     * @param frame
     */
    void renderFrame(const QImage &frame);
private:
    /**
     * @brief open
     * Open camera device
     */
    void open();
    /**
     * @brief startGrabbing
     * Start collect frame from camera
     * And establish the connection between ImageHandler & VideoSurface
     * @return
     */
    bool startGrabbing();
    /**
     * @brief stopGrabbing
     */
    void stopGrabbing();

    QPylonImageEventHandler*mImageEventHandler;
    QAbstractVideoSurface*  mVideoSurface;
    CInstantCamera*         mCamera;
    QRect                   mRect;
};
#endif // QPYLONCAMERA_H
