//
// Created by LXH on 2021/1/14.
//

#ifndef IRIS_RTC_BASE_H_
#define IRIS_RTC_BASE_H_

#include "iris_base.h"
#include "iris_media_base.h"

#ifdef __cplusplus
extern "C" {
#endif

enum EngineType {
  kEngineTypeNormal,
  kEngineTypeSubProcess,
};

enum ApiTypeEngine {
  kEngineInitialize = 0,
  kEngineRelease = 1,
  kEngineSetChannelProfile = 2,
  kEngineSetClientRole = 3,
  kEngineJoinChannel = 4,
  kEngineSwitchChannel = 5,
  kEngineLeaveChannel = 6,
  kEngineRenewToken = 7,
  kEngineRegisterLocalUserAccount = 8,
  kEngineJoinChannelWithUserAccount = 9,
  kEngineGetUserInfoByUserAccount = 10,
  kEngineGetUserInfoByUid = 11,
  kEngineStartEchoTest = 12,
  kEngineStopEchoTest = 13,
  kEngineSetCloudProxy = 14,
  kEngineEnableVideo = 15,
  kEngineDisableVideo = 16,
  kEngineSetVideoProfile = 17,
  kEngineSetVideoEncoderConfiguration = 18,
  kEngineSetCameraCapturerConfiguration = 19,
  kEngineSetupLocalVideo = 20,
  kEngineSetupRemoteVideo = 21,
  kEngineStartPreview = 22,
  kEngineSetRemoteUserPriority = 23,
  kEngineStopPreview = 24,
  kEngineEnableAudio = 25,
  kEngineEnableLocalAudio = 26,
  kEngineDisableAudio = 27,
  kEngineSetAudioProfile = 28,
  kEngineMuteLocalAudioStream = 29,
  kEngineMuteAllRemoteAudioStreams = 30,
  kEngineSetDefaultMuteAllRemoteAudioStreams = 31,
  kEngineAdjustUserPlaybackSignalVolume = 32,
  kEngineMuteRemoteAudioStream = 33,
  kEngineMuteLocalVideoStream = 34,
  kEngineEnableLocalVideo = 35,
  kEngineMuteAllRemoteVideoStreams = 36,
  kEngineSetDefaultMuteAllRemoteVideoStreams = 37,
  kEngineMuteRemoteVideoStream = 38,
  kEngineSetRemoteVideoStreamType = 39,
  kEngineSetRemoteDefaultVideoStreamType = 40,
  kEngineEnableAudioVolumeIndication = 41,
  kEngineStartAudioRecording = 42,
  kEngineStopAudioRecording = 43,
  kEngineStartAudioMixing = 44,
  kEngineStopAudioMixing = 45,
  kEnginePauseAudioMixing = 46,
  kEngineResumeAudioMixing = 47,
  kEngineSetHighQualityAudioParameters = 48,
  kEngineAdjustAudioMixingVolume = 49,
  kEngineAdjustAudioMixingPlayoutVolume = 50,
  kEngineGetAudioMixingPlayoutVolume = 51,
  kEngineAdjustAudioMixingPublishVolume = 52,
  kEngineGetAudioMixingPublishVolume = 53,
  kEngineGetAudioMixingDuration = 54,
  kEngineGetAudioMixingCurrentPosition = 55,
  kEngineSetAudioMixingPosition = 56,
  kEngineSetAudioMixingPitch = 57,
  kEngineGetEffectsVolume = 58,
  kEngineSetEffectsVolume = 59,
  kEngineSetVolumeOfEffect = 60,
  kEngineEnableFaceDetection = 61,
  kEnginePlayEffect = 62,
  kEngineStopEffect = 63,
  kEngineStopAllEffects = 64,
  kEnginePreloadEffect = 65,
  kEngineUnloadEffect = 66,
  kEnginePauseEffect = 67,
  kEnginePauseAllEffects = 68,
  kEngineResumeEffect = 69,
  kEngineResumeAllEffects = 70,
  kEngineGetEffectDuration = 71,
  kEngineSetEffectPosition = 72,
  kEngineGetEffectCurrentPosition = 73,
  kEngineEnableDeepLearningDenoise = 74,
  kEngineEnableSoundPositionIndication = 75,
  kEngineSetRemoteVoicePosition = 76,
  kEngineSetLocalVoicePitch = 77,
  kEngineSetLocalVoiceEqualization = 78,
  kEngineSetLocalVoiceReverb = 79,
  kEngineSetLocalVoiceChanger = 80,
  kEngineSetLocalVoiceReverbPreset = 81,
  kEngineSetVoiceBeautifierPreset = 82,
  kEngineSetAudioEffectPreset = 83,
  kEngineSetVoiceConversionPreset = 84,
  kEngineSetAudioEffectParameters = 85,
  kEngineSetVoiceBeautifierParameters = 86,
  kEngineSetLogFile = 87,
  kEngineSetLogFilter = 88,
  kEngineSetLogFileSize = 89,
  kEngineUploadLogFile = 90,
  kEngineSetLocalRenderMode = 91,
  kEngineSetRemoteRenderMode = 92,
  kEngineSetLocalVideoMirrorMode = 93,
  kEngineEnableDualStreamMode = 94,
  kEngineSetExternalAudioSource = 95,
  kEngineSetExternalAudioSink = 96,
  kEngineSetRecordingAudioFrameParameters = 97,
  kEngineSetPlaybackAudioFrameParameters = 98,
  kEngineSetMixedAudioFrameParameters = 99,
  kEngineAdjustRecordingSignalVolume = 100,
  kEngineAdjustPlaybackSignalVolume = 101,
  kEngineAdjustLoopBackRecordingSignalVolume = 102,
  kEngineEnableWebSdkInteroperability = 103,
  kEngineSetVideoQualityParameters = 104,
  kEngineSetLocalPublishFallbackOption = 105,
  kEngineSetRemoteSubscribeFallbackOption = 106,
  kEngineSwitchCamera = 107,
  kEngineSetDefaultAudioRouteToSpeakerPhone = 108,
  kEngineSetEnableSpeakerPhone = 109,
  kEngineEnableInEarMonitoring = 110,
  kEngineSetInEarMonitoringVolume = 111,
  kEngineIsSpeakerPhoneEnabled = 112,
  kEngineSetAudioSessionOperationRestriction = 113,
  kEngineEnableLoopBackRecording = 114,
  kEngineStartScreenCaptureByDisplayId = 115,
  kEngineStartScreenCaptureByScreenRect = 116,
  kEngineStartScreenCaptureByWindowId = 117,
  kEngineSetScreenCaptureContentHint = 118,
  kEngineUpdateScreenCaptureParameters = 119,
  kEngineUpdateScreenCaptureRegion = 120,
  kEngineStopScreenCapture = 121,
  kEngineStartScreenCapture = 122,
  kEngineSetVideoSource = 123,
  kEngineGetCallId = 124,
  kEngineRate = 125,
  kEngineComplain = 126,
  kEngineGetVersion = 127,
  kEngineEnableLastMileTest = 128,
  kEngineDisableLastMileTest = 129,
  kEngineStartLastMileProbeTest = 130,
  kEngineStopLastMileProbeTest = 131,
  kEngineGetErrorDescription = 132,
  kEngineSetEncryptionSecret = 133,
  kEngineSetEncryptionMode = 134,
  kEngineEnableEncryption = 135,
  kEngineRegisterPacketObserver = 136,
  kEngineCreateDataStream = 137,
  kEngineSendStreamMessage = 138,
  kEngineAddPublishStreamUrl = 139,
  kEngineRemovePublishStreamUrl = 140,
  kEngineSetLiveTranscoding = 141,
  kEngineAddVideoWaterMark = 142,
  kEngineClearVideoWaterMarks = 143,
  kEngineSetBeautyEffectOptions = 144,
  kEngineEnableVirtualBackground = 145,
  kEngineAddInjectStreamUrl = 146,
  kEngineStartChannelMediaRelay = 147,
  kEngineUpdateChannelMediaRelay = 148,
  kEnginePauseAllChannelMediaRelay = 149,
  kEngineResumeAllChannelMediaRelay = 150,
  kEngineStopChannelMediaRelay = 151,
  kEngineRemoveInjectStreamUrl = 152,
  kEngineSendCustomReportMessage = 153,
  kEngineGetConnectionState = 154,
  kEngineEnableRemoteSuperResolution = 155,
  kEngineRegisterMediaMetadataObserver = 156,
  kEngineSetParameters = 157,
  kEngineSetLocalAccessPoint = 158,
  kEngineUnRegisterMediaMetadataObserver = 159,
  kEngineSetMaxMetadataSize = 160,
  kEngineSendMetadata = 161,
  kEngineSetAppType = 162,
  kMediaPushAudioFrame = 163,
  kMediaPullAudioFrame = 164,
  kMediaSetExternalVideoSource = 165,
  kMediaPushVideoFrame = 166,
  kEngineSetAudioMixingPlaybackSpeed = 167,
  kEngineSelectAudioTrack = 168,
  kEngineGetAudioTrackCount = 169,
  kEngineSetAudioMixingDualMonoMode = 170,
  kEngineGetAudioFileInfo = 171,
  kEngineSetVideoProfileEx = 172,
  kMediaSetExternalAudioSourceVolume = 173,
  kEngineSetLogWriter = 174,
  kEngineReleaseLogWriter = 175,
  kEngineSetLocalVideoRenderer = 176,
  kEngineSetRemoteVideoRenderer = 177,
  kEngineSetCameraTorchOn = 178,
  kEngineIsCameraTorchSupported = 179,
  kEngineGetCameraMaxZoomFactor = 180,
  kEngineIsCameraAutoFocusFaceModeSupported = 181,
  kEngineIsCameraExposurePositionSupported = 182,
  kEngineIsCameraFocusSupported = 183,
  kEngineIsCameraZoomSupported = 184,
  kEngineSetCameraAutoFocusFaceModeEnabled = 185,
  kEngineSetCameraExposurePosition = 186,
  kEngineSetCameraFocusPositionInPreview = 187,
  kEngineSetCameraZoomFactor = 188,
  kEngineStartRhythmPlayer = 189,
  kEngineStopRhythmPlayer = 190,
  kEngineConfigRhythmPlayer = 191,
  kEngineGetNativeHandle = 192,
  kEngineGetScreenCaptureSources = 193,
  kEngineTakeSnapshot = 194,
  kEngineEnableContentInspect = 195,
  kEngineSetAVSyncSource = 196,
  kEngineStartRtmpStreamWithoutTranscoding = 197,
  kEngineStartRtmpStreamWithTranscoding = 198,
  kEngineUpdateRtmpTranscoding = 199,
  kEngineStopRtmpStream = 200,
  kEngineSetLowlightEnhanceOptions = 201,
  kEngineSetVideoDenoiserOptions = 202,
  kEngineSetColorEnhanceOptions = 203,
  kEngineEnableWirelessAccelerate = 204,
  kEngineMediaRecorderStart = 205,
  kEngineMediaRecorderStop = 206,
  kEngineEnableLocalVoicePitchCallback = 207,
  kEngineEnableSpatialAudio = 208,
  kEngineSetRemoteUserSpatialAudioParams = 209,
  kEngineSetScreenCaptureScenario = 210,
  kEngineEnableRemoteSuperResolution2 = 211,
  kEngineSetCameraCaptureRotation = 212,
};

enum ApiTypeChannel {
  kChannelCreateChannel = 0,
  kChannelRelease = 1,
  kChannelJoinChannel = 2,
  kChannelJoinChannelWithUserAccount = 3,
  kChannelLeaveChannel = 4,
  kChannelPublish = 5,
  kChannelUnPublish = 6,
  kChannelChannelId = 7,
  kChannelGetCallId = 8,
  kChannelRenewToken = 9,
  kChannelSetEncryptionSecret = 10,
  kChannelSetEncryptionMode = 11,
  kChannelEnableEncryption = 12,
  kChannelRegisterPacketObserver = 13,
  kChannelRegisterMediaMetadataObserver = 14,
  kChannelUnRegisterMediaMetadataObserver = 15,
  kChannelSetMaxMetadataSize = 16,
  kChannelSendMetadata = 17,
  kChannelSetClientRole = 18,
  kChannelSetRemoteUserPriority = 19,
  kChannelSetRemoteVoicePosition = 20,
  kChannelSetRemoteRenderMode = 21,
  kChannelSetDefaultMuteAllRemoteAudioStreams = 22,
  kChannelSetDefaultMuteAllRemoteVideoStreams = 23,
  kChannelMuteLocalAudioStream = 24,
  kChannelMuteLocalVideoStream = 25,
  kChannelMuteAllRemoteAudioStreams = 26,
  kChannelAdjustUserPlaybackSignalVolume = 27,
  kChannelMuteRemoteAudioStream = 28,
  kChannelMuteAllRemoteVideoStreams = 29,
  kChannelMuteRemoteVideoStream = 30,
  kChannelSetRemoteVideoStreamType = 31,
  kChannelSetRemoteDefaultVideoStreamType = 32,
  kChannelCreateDataStream = 33,
  kChannelSendStreamMessage = 34,
  kChannelAddPublishStreamUrl = 35,
  kChannelRemovePublishStreamUrl = 36,
  kChannelSetLiveTranscoding = 37,
  kChannelAddInjectStreamUrl = 38,
  kChannelRemoveInjectStreamUrl = 39,
  kChannelStartChannelMediaRelay = 40,
  kChannelUpdateChannelMediaRelay = 41,
  kChannelPauseAllChannelMediaRelay = 42,
  kChannelResumeAllChannelMediaRelay = 43,
  kChannelStopChannelMediaRelay = 44,
  kChannelGetConnectionState = 45,
  kChannelEnableRemoteSuperResolution = 46,
  kChannelSetAVSyncSource = 47,
  kChannelStartRtmpStreamWithoutTranscoding = 48,
  kChannelStartRtmpStreamWithTranscoding = 49,
  kChannelUpdateRtmpTranscoding = 50,
  kChannelStopRtmpStream = 51,
  kChannelSetRemoteUserSpatialAudioParams = 52,
  kChannelEnableRemoteSuperResolution2 = 53,

};

enum ApiTypeAudioDeviceManager {
  kADMEnumeratePlaybackDevices = 0,
  kADMSetPlaybackDevice = 1,
  kADMGetPlaybackDevice = 2,
  kADMGetPlaybackDeviceInfo = 3,
  kADMSetPlaybackDeviceVolume = 4,
  kADMGetPlaybackDeviceVolume = 5,
  kADMSetPlaybackDeviceMute = 6,
  kADMGetPlaybackDeviceMute = 7,
  kADMStartPlaybackDeviceTest = 8,
  kADMStopPlaybackDeviceTest = 9,
  kADMEnumerateRecordingDevices = 10,
  kADMSetRecordingDevice = 11,
  kADMGetRecordingDevice = 12,
  kADMGetRecordingDeviceInfo = 13,
  kADMSetRecordingDeviceVolume = 14,
  kADMGetRecordingDeviceVolume = 15,
  kADMSetRecordingDeviceMute = 16,
  kADMGetRecordingDeviceMute = 17,
  kADMStartRecordingDeviceTest = 18,
  kADMStopRecordingDeviceTest = 19,
  kADMStartAudioDeviceLoopbackTest = 20,
  kADMStopAudioDeviceLoopbackTest = 21,
  kADMFollowSystemPlaybackDevice = 22,
  kADMFollowSystemRecordingDevice = 23,
};

enum ApiTypeVideoDeviceManager {
  kVDMEnumerateVideoDevices = 0,
  kVDMSetDevice = 1,
  kVDMGetDevice = 2,
  kVDMStartDeviceTest = 3,
  kVDMStopDeviceTest = 4,
};

enum ApiTypeRawDataPluginManager {
  kRDPMRegisterPlugin = 0,
  kRDPMUnregisterPlugin = 1,
  kRDPMHasPlugin = 2,
  kRDPMEnablePlugin = 3,
  kRDPMGetPlugins = 4,
  kRDPMSetPluginParameter = 5,
  kRDPMGetPluginParameter = 6,
  kRDPMRelease = 7,
};

enum VideoObserverPosition {
  kPositionPostCapturer = 1 << 0,
  kPositionPreRenderer = 1 << 1,
  kPositionPreEncoder = 1 << 2,
};

#ifdef __cplusplus
}
#endif

#endif//IRIS_RTC_BASE_H_
