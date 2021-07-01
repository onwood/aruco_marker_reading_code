# aruco_marker_reading_code

aruco marker를 opencv로 읽어오는 코드를 활용했습니다.
(출처: https://github.com/pal-robotics/aruco_ros.git)

해당 코드에서 marker id에 구애를 받지 않고 모든 marker id 별 pose 정보를 marker id별로 구분해서 받아오는 코드입니다.
코드를 읽어오는 노드는 /aruco_single/marker 토픽을 사용했습니다.

부분별하게 들어오는 데이터를 id로 구분하기 위해서 aruco_marker_reading_code/aruco_ros/aruco_ros/src/simple_single.cpp 에서
255번째 줄 
visMarker.id = 1;을 visMarker.id = markers[i].id;로 수정해서 id로 구분할 수 있도록 변경하여 사용했습니다.
