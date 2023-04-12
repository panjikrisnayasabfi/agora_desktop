// import 'dart:convert';

import 'package:agora_rtc_engine/rtc_engine.dart';
import 'package:agora_rtc_engine/rtc_local_view.dart' as rtc_local_view;
import 'package:agora_rtc_engine/rtc_remote_view.dart' as rtc_remote_view;
import 'package:flutter/material.dart';
// import 'package:http/http.dart' as http;

// import '../../../../core/resources/values.dart';
// import '../../../../core/utils/url_util.dart';

class VideoCallScreen extends StatefulWidget {
  const VideoCallScreen({Key? key}) : super(key: key);

  @override
  State<VideoCallScreen> createState() => _VideoCallScreenState();
}

class _VideoCallScreenState extends State<VideoCallScreen> {
  late RtcEngine _engine;

  // final UrlString _urlString = UrlString();
  final String _appId = 'bed0a3880a7f42c69b6c6cafbf37084d';
  final String _channel = 'agora-test';
  // final String _clientId = '1';
  // final String _agentId = '97103101110116';
  final String _rtcToken =
      '007eJxTYMgWtDdb+ueU3h+lw47/8p1il+Y/7T+iqvHq4Cnx6PMnH7EpMCSlphgkGltYGCSap5kYJZtZJpklmyUnpiWlGZsbWJikbHSVSDaaLpncJ9DAzMgAgSA+F0Nien5Rom5JanEJAwMAg0UjbA==';
  int? _remoteUid;
  bool _localUserJoined = false;

  // Future<void> _getToken(String channel, String agentId) async {
  //   final response = await http.get(
  //       Uri.parse('${urlAgoraServer}rte/$channel/publisher/uid/$agentId'),
  //       headers: _urlString.getHeader());

  //   if (response.statusCode == 200) {
  //     setState(() {
  //       _rtcToken = response.body;
  //       _rtcToken = jsonDecode(_rtcToken)['rtcToken'];
  //     });
  //   }
  // }

  Future<void> _initAgora() async {
    // retrieve permissions
    // await [Permission.microphone, Permission.camera].request();

    // await _getToken(_channel, _agentId);

    // create the engine
    _engine = await RtcEngine.create(_appId);
    // await _engine.enableAudio();
    await _engine.enableVideo();
    // await _engine.setChannelProfile(ChannelProfile.LiveBroadcasting);
    // await _engine.setClientRole(ClientRole.Broadcaster);

    _engine.setEventHandler(
      RtcEngineEventHandler(
        joinChannelSuccess: (String channel, int uid, int elapsed) {
          print('local user $uid joined');
          setState(() {
            _localUserJoined = true;
          });
        },
        userJoined: (int uid, int elapsed) {
          print('remote user $uid joined');
          setState(() {
            _remoteUid = uid;
          });
        },
        userOffline: (int uid, UserOfflineReason reason) {
          print('remote user $uid left channel');
          setState(() {
            _remoteUid = uid;
          });
        },
        error: (ErrorCode error) {
          print('error ${error.name}');
        },
      ),
    );

    await _engine.joinChannel(
      _rtcToken,
      _channel,
      null,
      0,
    );
  }

  @override
  void initState() {
    _initAgora();
    super.initState();
  }

  // Create UI with local view and remote view
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Agora Video Call'),
      ),
      body: Stack(
        children: [
          Center(
            child: _remoteVideo(),
          ),
          Align(
            alignment: Alignment.topLeft,
            child: SizedBox(
              width: 100,
              height: 150,
              child: Center(
                child: _localUserJoined
                    ? rtc_local_view.SurfaceView()
                    : const CircularProgressIndicator(),
                // child: rtc_local_view.SurfaceView(),
              ),
            ),
          ),
        ],
      ),
    );
  }

  // Display remote user's video
  Widget _remoteVideo() {
    if (_remoteUid != null) {
      return rtc_remote_view.SurfaceView(
        uid: _remoteUid!,
        channelId: _channel,
      );
    } else {
      return const Text(
        'Please wait for remote user to join',
        textAlign: TextAlign.center,
      );
    }
  }
}
