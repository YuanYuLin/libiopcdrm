#ifndef __OPS_DRM_H__
#define __OPS_DRM_H__

#include <xf86drm.h>
#include <xf86drmMode.h>

#define DRM_CARD	"/dev/dri/card%d"
#define DEPTH		24
#define BPP		32

struct drm_dev_t {
	uint32_t conn_id;
	uint32_t enc_id;
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t width;
	uint32_t height;
	uint32_t pitch;
	uint32_t size;
	uint32_t handle;
	drmModeModeInfo mode;
	drmModeCrtc *saved_crtc;
	struct drm_dev_t *next;
	uint32_t *buf;
};

struct ops_drm_t {
    void (*init) (void);
    void (*show_all) (void);

    int (*open)(uint8_t *path);
    struct drm_dev_t* (*find_dev)(int fd);
    void (*setup)(int fd, struct drm_dev_t *dev);
    void (*close)(int fd, struct drm_dev_t *dev_head);

};

struct ops_drm_t* get_drm_instance();
void del_drm_instance();
#endif
